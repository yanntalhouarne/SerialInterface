#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("COM Port"));

    //m_console = new Console(ui->ConsoleWidget);
    m_serial = new QSerialPort(this);
    ui->autoscroll->setChecked(true);
    m_settings = new serialPortSettingsDialog(this);
    m_settings->setDefault();

    m_parsingSettingsDialog = new serialParsingSettingsDialog(this);

    /* POPULATE COMBO BOX WITH AVAILABLE COM PORTS */
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->term_comboBox->addItem(info.portName());


    /* Set up plot */
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);

    /* CONNECT QACTIONS */
    /* MENU */

    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::connectToPort);
    connect(ui->actionRefresh, &QAction::triggered, this, &MainWindow::refreshPortList);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::disconnectToPort);
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::clearTextEdit);
    connect(ui->actionConfigurePort, &QAction::triggered, m_settings, &serialPortSettingsDialog::show);
    connect(ui->actionToggle_Auto_Scroll, &QAction::triggered, ui->autoscroll, &QCheckBox::toggle);

    connect(ui->actionParsing, &QAction::triggered, m_parsingSettingsDialog, &serialParsingSettingsDialog::show);

    /* TERMINAL WIDGET */
    connect(ui->ConnectButton, &QPushButton::clicked, this, &MainWindow::connectToPort);
    connect(ui->DisconnectButton, &QPushButton::clicked, this, &MainWindow::disconnectToPort);
    connect(ui->RefreshButton, &QPushButton::clicked, this, &MainWindow::refreshPortList);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::processData);
    connect(ui->autoscroll, &QCheckBox::stateChanged, this, &MainWindow::changeScrolling);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearTextEdit);

    /* PLOT WIDGET */
    connect(ui->clearPlot, &QPushButton::clicked, this, &MainWindow::clearData);

}

MainWindow::~MainWindow()
{
    delete m_settings;
    delete ui;
}

void MainWindow::connectToPort()
{
    m_serial->close(); // close all other ports (if no PORT is open, this function can still be called)
    m_settings->setPort(ui->term_comboBox->currentText()); // set the current port in the combo box to the current settings
    m_serial->setPortName(ui->term_comboBox->currentText());
    const serialPortSettingsDialog::Settings p = m_settings->settings(); // get a copy of the current settings
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (!m_serial->open(QIODevice::ReadWrite))     // open the PORT, emit the error signal if failed
    {
        ui->consoleStatusLabel->setText(tr("Can't open %1, error code %2")
                   .arg(m_serial->portName())
                   .arg(m_serial->error()));
        return;
    }
    else
    {
        ui->consoleStatusLabel->setText(tr("Connected to %1.      (BaudRate: %2, DataBits: %3, Parity: %4, StopBits: %5, FlowCtl: %6)")
                    .arg(p.name)
                    .arg(p.stringBaudRate)
                    .arg(p.stringDataBits)
                    .arg(p.stringParity)
                    .arg(p.stringStopBits)
                    .arg(p.stringFlowControl));
    }
}

void MainWindow::disconnectToPort()
{
    m_serial->close(); // close all other ports (if no PORT is open, this function can still be called)
    ui->consoleStatusLabel->setText(tr("Not connected."));
}

void MainWindow::processData()
{
    // get the parsing settings
    const serialParsingSettingsDialog::parsingSettings p = m_parsingSettingsDialog->getParsingSettings();

    // get the data as a byte array
    const QByteArray rxData = m_serial->readAll();

    // trailing check variable
    char trailingChar = 0;

    // x-y value for the plot
    static double x = 0;
    double y = 0;

    // update console
    switch (p.dataFormat)
    {
        case 0: // ASCII
        {
            if (ui->printCheckBox->isChecked())
            {
                ui->m_console->putData(rxData);
            }
            // update plot
            y = rxData.toDouble(); // convert from ASCII character to a double value
            if (ui->plotCheckBox->isChecked())
            {
                addPoint(x, y);
                plot();
            }
            break;
        } // end of: case 0: ASCII
        case 1: // RAW
        {
            long Data = 0;
            switch (p.byteNbr)
            {
                case 1:
                {
                    if (rxData.size() >= 2)
                    {
                       Data = ((0x000000FF)&(rxData[0]));
                       trailingChar = rxData[1];
                    }
                    break;
                }
                case 2:
                {
                    if (rxData.size() >= 3)
                    {
                       Data = ((0x000000FF)&(rxData[0])) | ((0x0000FF00)&(rxData[1]<<8));
                       trailingChar = rxData[2];
                    }
                    break;
                }
                case 3:
                {
                    if (rxData.size() >= 4)
                    {
                       Data = ((0x000000FF)&(rxData[0])) | ((0x0000FF00)&(rxData[1]<<8)) | ((0x00FF0000)&(rxData[2]<<16));
                       trailingChar = rxData[3];
                    }
                    break;
                }
                case 4:
                {
                    if (rxData.size() >= 5)
                    {
                       Data = ((0x000000FF)&(rxData[0])) | ((0x0000FF00)&(rxData[1]<<8)) | ((0x00FF0000)&(rxData[2]<<16)) | ((0xFF000000)&(rxData[3]<<24));
                       trailingChar = rxData[4];
                    }
                    break;
                }
                default:
                    break;
            } // end of: switch (p.byteNbr)
            QString strAscii = QString::number(Data);
            QByteArray baAscii = strAscii.toUtf8();
            baAscii.append(13);
            // update console
            if (ui->printCheckBox->isChecked())
            {
                if (trailingChar == 13) // check trailing character is NL
                    ui->m_console->putData(baAscii);
            }

            // update plot
            y = Data; // convert from ASCII character to a double value
            if (ui->plotCheckBox->isChecked())
            {
                if (trailingChar == 13) // check trailing character is NL
                {
                    addPoint(x, y);
                    plot();
                }
            }
        break;
        } // end of: case 1: RAW
        default:
        break;
    } // end of: switch (p.dataFormat)

    // INCREMENT X VALUE
    if (x > 2000)
    {
        x = 0;
        clearData();
    }
    x++;
}

void MainWindow::clearTextEdit()
{
    ui->m_console->clear();
}

void MainWindow::changeScrolling()
{
    if (ui->autoscroll->isChecked())
        ui->m_console->autoScroll = 1;
    else
        ui->m_console->autoScroll = 0;
}

/* Refresh combo boxes */
void MainWindow::refreshPortList()
{
    // refresh MainWindow combobox
    ui->term_comboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->term_comboBox->addItem(info.portName());

    // refresh Settings combobox
    m_settings->fillPortsInfo();
}

/* PLOTTING FUNCTIONS */
void MainWindow::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);
    ui->plot->rescaleAxes(0);
}

void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();

}

void MainWindow::plot()
{
    ui->plot->graph(0)->setData(qv_x, qv_y);
    ui->plot->replot();
    ui->plot->update();
}


