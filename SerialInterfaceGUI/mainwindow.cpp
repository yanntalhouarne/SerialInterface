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

    /* POPULATE COMBO BOX WITH AVAILABLE COM PORTS */
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->term_comboBox->addItem(info.portName());

    /* CONNECT QACTIONS */
    /* MENU */
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::connectToPort);
    connect(ui->actionRefresh, &QAction::triggered, this, &MainWindow::refreshPortList);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::disconnectToPort);
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::clearTextEdit);
    connect(ui->actionConfigurePort, &QAction::triggered, m_settings, &serialPortSettingsDialog::show);
    connect(ui->actionToggle_Auto_Scroll, &QAction::triggered, ui->autoscroll, &QCheckBox::toggle);

    /* TERMINAL WIDGET */
    connect(ui->ConnectButton, &QPushButton::clicked, this, &MainWindow::connectToPort);
    connect(ui->DisconnectButton, &QPushButton::clicked, this, &MainWindow::disconnectToPort);
    connect(ui->RefreshButton, &QPushButton::clicked, this, &MainWindow::refreshPortList);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::processData);
    connect(ui->autoscroll, &QCheckBox::stateChanged, this, &MainWindow::changeScrolling);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::clearTextEdit);



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
                   .arg(m_serial->portName()).arg(m_serial->error()));
        return;
    }
    else
    {
        ui->consoleStatusLabel->setText(tr("Connected to %1.      (BaudRate: %2, DataBits: %3, Parity: %4, StopBits: %5, FlowCtl: %6)")
                    .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                    .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    }
}

void MainWindow::disconnectToPort()
{
    m_serial->close(); // close all other ports (if no PORT is open, this function can still be called)
    ui->consoleStatusLabel->setText(tr("Not connected."));
}

void MainWindow::processData()
{
    const QByteArray rxData = m_serial->readAll();
    ui->m_console->putData(rxData);
}

void MainWindow::clearTextEdit()
{
    ui->m_console->clear();
}

void MainWindow::changeScrolling()
{
    if (ui->autoscroll->isChecked())
    {
        ui->m_console->autoScroll = 1;
    }
    else
    {
        ui->m_console->autoScroll = 0;
    }
}

void MainWindow::refreshPortList()
{
    ui->term_comboBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->term_comboBox->addItem(info.portName());
}
