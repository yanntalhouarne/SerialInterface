#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Serial Port Communicatrion Tool"));

// CONSOLE
    ui->rowNbrSpinBox->setRange(1, 5000);
    ui->rowNbrSpinBox->setValue(100);
    ui->m_console->setMaximumBlockCount(1000);

// SERIAL PORT
    m_serial = new QSerialPort(this);

// SETTINGS
    m_settings = new serialPortSettingsDialog(this);
    m_settings->setDefault();


// PORT CONNECTION FAILED DIALOG
    m_portConnFailureDialog = new PortConnFailureDialog(this);

// PARSING SETTINGS
    m_parsingSettingsDialog = new serialParsingSettingsDialog(this);

    // LOGGING SETTINGS
    m_loggingSettingsDialog = new LoggingSettingsDialog(this);


    /* POPULATE COMBO BOX WITH AVAILABLE COM PORTS */
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->term_comboBox->addItem(info.portName());

    /* STM32 BOOTLOADER DIALOG */
    m_stm32bootloaderDialog = new stm32bootloaderDialog(this); 
    m_bootloaderInfoDialog = new bootloaderInfoDialog(m_stm32bootloaderDialog);


    /* Set up plot */
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    // X-AXIS RANGE SPINBOX
    ui->xAxisRangeSpinbox->setRange(0, 100000);
    ui->xAxisRangeSpinbox->setValue(xAxisRange);
    // Y-AXIS RANGE SPIN BOX
    ui->yAxisLowerSpinbox->setRange(-100000, 100000);
    ui->yAxisLowerSpinbox->setValue(yAxisLower);
    ui->yAxisUpperSpinbox->setRange(-100000, 100000);
    ui->yAxisUpperSpinbox->setValue(yAxisUpper);

/* DEFAULT/INITIAL SETTINGS */
    ui->actionConnect->setDisabled(0);
    ui->actionDisconnect->setDisabled(1);

    ui->ConnectButton->setDisabled(0);
    ui->DisconnectButton->setDisabled(1);

    ui->autoscroll->setChecked(true);
    ui->consoleStatusLabel->setText("Not connected.");

    ui->asciiFormatCheckbox->setChecked(1);
    ui->parsingLabel->setText("parsing: ASCII");
    ui->parsingLabel->setToolTip("Received data is in ASCII format.");

    ui->printCheckBox->setChecked(1);
    ui->plotCheckBox->setToolTip("Data format must be ASCII or CR/CS format.\nSee parsing settings.");
    ui->plotCheckBox->setChecked(0);

    ui->sendButton->setDisabled(1);
    ui->lfCheckBox->setChecked(0);
    ui->crCheckBox->setChecked(0);



/* TOP MENU BAR QACTIONS */
    // PORT
    connect(ui->actionConnect,            &QAction::triggered,      this,                     &MainWindow::connectToPort);
    connect(ui->actionRefresh,            &QAction::triggered,      this,                     &MainWindow::refreshPortList);
    connect(ui->actionDisconnect,         &QAction::triggered,      this,                     &MainWindow::disconnectToPort);
    connect(ui->actionConfigurePort,      &QAction::triggered,      m_settings,               &serialPortSettingsDialog::show);
    // CONSOLE
    connect(ui->actionClear,              &QAction::triggered,      this,                     &MainWindow::clearTextEdit);
    connect(ui->actionToggle_Auto_Scroll, &QAction::triggered,      ui->autoscroll,           &QCheckBox::toggle);
    connect(ui->actionParsing,            &QAction::triggered,      m_parsingSettingsDialog,  &serialParsingSettingsDialog::show);
    connect(ui->rowNbrSpinBox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),  this,                  &MainWindow::changeNbrRows);
    connect(ui->rowNbrSpinBox,           &QSpinBox::editingFinished,                          ui->rowNbrSpinBox, &QSpinBox::clearFocus);
    // LOG
    connect(ui->actionStart_logging,      &QAction::triggered,      this,                     &MainWindow::startLogging);
    connect(ui->actionStop_logging,       &QAction::triggered,      this,                     &MainWindow::stopLogging);
    connect(ui->actionConfigure_logging,  &QAction::triggered,      m_loggingSettingsDialog,  &LoggingSettingsDialog::show);
    connect(ui->menuLogs,                 &QMenu::aboutToShow,      this,                     &MainWindow::checkLogEnabledFlag);
    connect(ui->actionConfigure_logging,  &QAction::hovered,        m_loggingSettingsDialog,  &LoggingSettingsDialog::updateLoggingCheckBox);
    // STM32 BOOTLOADER
    connect(ui->actionBootloaderConfigure,  &QAction::triggered,    m_stm32bootloaderDialog,  &stm32bootloaderDialog::show);
    connect(ui->actionBootloaderInfo,       &QAction::triggered,    m_bootloaderInfoDialog,   &bootloaderInfoDialog::show);

/* TERMINAL WIDGET */
    connect(ui->ConnectButton,            &QPushButton::clicked,    this,                     &MainWindow::connectToPort);
    connect(ui->DisconnectButton,         &QPushButton::clicked,    this,                     &MainWindow::disconnectToPort);
    connect(ui->RefreshButton,            &QPushButton::clicked,    this,                     &MainWindow::refreshPortList);
    connect(m_serial,                     &QSerialPort::readyRead,  this,                     &MainWindow::processData);
    connect(ui->autoscroll,               &QCheckBox::stateChanged, this,                     &MainWindow::changeScrolling);
    connect(ui->clearButton,              &QPushButton::clicked,    this,                     &MainWindow::clearTextEdit);
    connect(m_parsingSettingsDialog->getApplyButton(), &QPushButton::clicked, this, &MainWindow::updateParsingLabelAndCheckbox);


/* TX CONSOLE */
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendToPort);
    connect(ui->asciiFormatCheckbox, &QCheckBox::stateChanged, this, &MainWindow::updateParsingSettingsFromCheckBox);


/* PLOT WIDGET */
    connect(ui->clearPlot,                &QPushButton::clicked,                                 this,                  &MainWindow::clearData);
    connect(ui->xAxisRangeSpinbox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,                  &MainWindow::changeAxisRange_X);
    connect(ui->yAxisLowerSpinbox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,                  &MainWindow::changeLowerAxisRange_Y);
    connect(ui->yAxisUpperSpinbox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this,                  &MainWindow::changeUpperAxisRange_Y);
    connect(ui->xAxisRangeSpinbox,        &QSpinBox::editingFinished,                            ui->xAxisRangeSpinbox, &QSpinBox::clearFocus);
    connect(ui->yAxisLowerSpinbox,        &QSpinBox::editingFinished,                            ui->yAxisLowerSpinbox, &QSpinBox::clearFocus);
    connect(ui->yAxisUpperSpinbox,        &QSpinBox::editingFinished,                            ui->yAxisUpperSpinbox, &QSpinBox::clearFocus);
    connect(ui->xAxisAutoRangeCheckbox,   &QCheckBox::stateChanged,                              this,                  &MainWindow::changeAxisAutoRange);


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
        connectedToPort = 0;
        // activate "Connect" actions/buttons
        ui->ConnectButton->setDisabled(0);
        ui->actionConnect->setDisabled(0);
        // de-activate "Disconnect" actions/buttons
        ui->DisconnectButton->setDisabled(1);
        ui->actionDisconnect->setDisabled(1);
        m_portConnFailureDialog->setTextLabel(tr("Can't open %1, error code %2")
                   .arg(m_serial->portName())
                   .arg(m_serial->error()));
        m_portConnFailureDialog->show();

        ui->consoleStatusLabel->setText(tr("Could not open %1, error code %2")
                   .arg(m_serial->portName())
                   .arg(m_serial->error()));
        return;
    }
    else
    {
        connectedToPort = 1;
        ui->ConnectButton->setDisabled(1);
        ui->actionConnect->setDisabled(1);
        ui->DisconnectButton->setDisabled(0);
        ui->actionDisconnect->setDisabled(0);
        ui->consoleStatusLabel->setText(tr("Connected to %1.      (BaudRate: %2, DataBits: %3, Parity: %4, StopBits: %5, FlowCtl: %6)")
                    .arg(p.name)
                    .arg(p.stringBaudRate)
                    .arg(p.stringDataBits)
                    .arg(p.stringParity)
                    .arg(p.stringStopBits)
                    .arg(p.stringFlowControl));
        ui->sendButton->setDisabled(0);
    }
}

void MainWindow::disconnectToPort()
{
    connectedToPort = 0;
    ui->ConnectButton->setDisabled(0);
    ui->actionConnect->setDisabled(0);
    ui->DisconnectButton->setDisabled(1);
    ui->actionDisconnect->setDisabled(1);
    ui->sendButton->setDisabled(1);
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
    char checksum = 0;

    // x-y value for the plot
    static double x = 0;
    double y = 0;

    // update console
    switch (p.dataFormat)
    {
        case ASCII:
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
        } // end of: case ASCII
        case RAW_BYTE_FORMAT:
        {
            for (int i = 0; i < rxData.size(); i++)
            {
               // update console
               if (ui->printCheckBox->isChecked())
               {
                    ui->m_console->putData(rxData);
               }
            }
            break;
        } // end of: case ASCII
        case RAW_DATA_CHECKSUM:
        {
            long Data = 0;
            switch (p.byteNbr)
            {
                case 1:
                {
                    if (rxData.size() >= 3)
                    {
                       Data = ((0x000000FF)&(rxData[0]));
                       checksum = rxData[1];
                       trailingChar = rxData[2];
                       if (checksum == (rxData[0] ^ trailingChar))
                           checksum = 1;
                        else
                           checksum = 0;

                    }
                    break;
                }
                case 2:
                {
                    if (rxData.size() >= 4)
                    {
                       Data = ((0x000000FF)&(rxData[0])) | ((0x0000FF00)&(rxData[1]<<8));
                       checksum = rxData[2];
                       trailingChar = rxData[3];
                       if (checksum == (rxData[0] ^ rxData[1] ^ trailingChar))
                           checksum = 1;
                        else
                           checksum = 0;
                    }
                    break;
                }
                case 4:
                {
                    if (rxData.size() >= 6)
                    {
                       Data = ((0x000000FF)&(rxData[0])) | ((0x0000FF00)&(rxData[1]<<8)) | ((0x00FF0000)&(rxData[2]<<16)) | ((0xFF000000)&(rxData[3]<<24));
                       checksum = rxData[4];
                       trailingChar = rxData[5];
                       if (checksum == (rxData[0] ^ rxData[1] ^ rxData[2] ^ trailingChar))
                           checksum = 1;
                        else
                           checksum = 0;
                    }
                    break;
                } // end of: case RAW:
                default:
                    break;
            } // end of: switch (p.byteNbr)
            QString strAscii = QString::number(Data);

            QByteArray baAscii = strAscii.toUtf8();
            baAscii.append(13);
            // update console
            if (ui->printCheckBox->isChecked())
            {
                if ((trailingChar == 13) && checksum) // check trailing character is NL
                    ui->m_console->putData(baAscii);
            }

            // update plot
            y = Data; // convert from ASCII character to a double value
            if (ui->plotCheckBox->isChecked())
            {
                if ((trailingChar == 13) && checksum)  // check trailing character is NL
                {
                    addPoint(x, y);
                    plot();
                }
            }

            // update logging
            if (startedLoggingToFile)
            {
                if ((trailingChar == 13) && checksum)
                {
                    m_loggingSettingsDialog->appendToFile(baAscii);
                }

            }
        break;
        } // end of: case 1: RAW
        case STM32_BOOTLOADER_MODE:
        {
            // this slot should bne disconnected from the RX signal when STM32_BOOTLOADER_MODE is activated
            //m_stm32Interpreter.parseCmd(ui->m_console, rxData);
            //break;
        }
        default:
        break;
    } // end of: switch (p.dataFormat)

    // INCREMENT X VALUE
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
    if (qv_x.size() > 100000)
        qv_x.clear();
    if (qv_y.size() > 100000)
        qv_y.clear();

    qv_x.append(x);
    qv_y.append(y);

    /* X-AXIS SCALING */
    if (ui->xAxisAutoRangeCheckbox->isChecked())
    {
        ui->plot->xAxis->rescale(0);
    }
    else
    {
        if (x < xAxisRange)
        {
             ui->plot->xAxis->setRangeLower(0);
             ui->plot->xAxis->setRangeUpper(xAxisRange);
        }
        else
        {
            ui->plot->xAxis->setRangeLower(x-xAxisRange);
            ui->plot->xAxis->setRangeUpper(x);
        }
    }

    /* Y-AXIS SCALING */
    if (ui->yAxisAutoRangeCheckbox->isChecked())
    {
        ui->plot->yAxis->rescale(0);
    }
    else
    {
        ui->plot->yAxis->setRangeLower(yAxisLower);
        ui->plot->yAxis->setRangeUpper(yAxisUpper);
    }
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

void MainWindow::changeAxisRange_X(int val)
{
    xAxisRange = val;
}

void MainWindow::changeLowerAxisRange_Y(int val)
{
    if (val >= yAxisUpper) // if the lower range is bigger than the upper range, set the lower range (and the spin box) to upper - 10
        ui->yAxisLowerSpinbox->setValue(yAxisUpper-10);
    else
        yAxisLower = val;
}

void MainWindow::changeUpperAxisRange_Y(int val)
{
    if (val <= yAxisLower) // if the lower range is bigger than the upper range, set the lower range (and the spin box) to upper - 10
        ui->yAxisUpperSpinbox->setValue(yAxisLower+10);
    else
        yAxisUpper = val;
}

void MainWindow::changeAxisAutoRange()
{
    if (ui->xAxisAutoRangeCheckbox->isChecked())
    {
        ui->xAxisRangeSpinbox->setDisabled(1);
    }
    else
    {
        ui->xAxisRangeSpinbox->setEnabled(1);
    }

    if (ui->yAxisAutoRangeCheckbox->isChecked())
    {
        ui->yAxisLowerSpinbox->setDisabled(1);
        ui->yAxisUpperSpinbox->setDisabled(1);
    }
    else
    {
        ui->yAxisLowerSpinbox->setEnabled(1);
        ui->yAxisUpperSpinbox->setEnabled(1);
    }


}

void MainWindow::changeNbrRows(int val)
{
    ui->m_console->setMaximumBlockCount(val);
}

void MainWindow::stopLogging()
{
    startedLoggingToFile = 0;
    m_loggingSettingsDialog->closeFile();
}

void MainWindow::startLogging()
{
    //m_loggingSettingsDialog->openFile();
    if(m_loggingSettingsDialog->isFileOpened())
    {
        if(m_loggingSettingsDialog->isLoggingEnabled()) // check if enabled checkbox is checked
        {
            startedLoggingToFile = 1;
            ui->actionStart_logging->setDisabled(1);
        }
    }
    ui->actionStop_logging->setDisabled(0);
}

void MainWindow::checkLogEnabledFlag()
{
    if (m_loggingSettingsDialog->isLoggingEnabled() && m_loggingSettingsDialog->isFileOpened() && (!didLoggingStart())) // file opened, loggign enabled, logging not started
    {
        ui->actionStart_logging->setDisabled(0);
        ui->actionStop_logging->setDisabled(1);
    }
    else if (m_loggingSettingsDialog->isLoggingEnabled() && m_loggingSettingsDialog->isFileOpened() && didLoggingStart()) // file opened, loggign enabled, logging started
    {
        ui->actionStart_logging->setDisabled(1);
        ui->actionStop_logging->setDisabled(0);
    }
    else // file not opened and/or logging disabled
    {
        ui->actionStart_logging->setDisabled(1);
        ui->actionStop_logging->setDisabled(1);
    }
}

bool MainWindow::didLoggingStart()
{
    return startedLoggingToFile;
}

bool MainWindow::isConnected()
{
    return connectedToPort;
}

void MainWindow::sendToPort()
{
    // flush the serial port
    m_serial->clear();

    // get the parsing settings
    const serialParsingSettingsDialog::parsingSettings p = m_parsingSettingsDialog->getParsingSettings();

    // get string from TX text edit box
    QString stringToSend = ui->txConsoleTextEdit->toPlainText();
    QByteArray bArray = stringToSend.toLocal8Bit();
    //QByteArray hexArray = stringToSend.fromLocal8Bit();

    switch (p.dataFormat)
    {
        case ASCII:
        {

            if (ui->crCheckBox->isChecked())
            {
                bArray.append(13);
            }
            if (ui->lfCheckBox->isChecked())
            {
                bArray.append(10);
            }

            if (connectedToPort) // make sure we are connected to the PORT
            {
                m_serial->write(bArray);
            }
            break;
        }
        case RAW_DATA_CHECKSUM:
        {
            QByteArray txBuffer;
            int nbrBytes = 0;
            int i = 0;
            QString tempChar;
            while (bArray.size() > i+4)
            {
                if ((bArray[i] == '0')&&(bArray[i+1] == 'x'))
                {
                    nbrBytes++;
                    tempChar.append((QChar)bArray[i+2]);
                    tempChar.append((QChar)bArray[i+3]);
                    bool ok;
                    int hex = tempChar.toInt(&ok, 16);
                    tempChar.clear();
                    txBuffer.append(hex);
                }
                if (bArray[i+4] == ',')
                {
                    i+=5;
                }
                else
                {
                    break;
                }
            }
            m_serial->write(txBuffer);
            break;
        }
        case STM32_BOOTLOADER_MODE:
        {
            if (bArray.size() >= 4)
            {
                // stop asynch mode for the serialport RX
                disconnect(m_serial, &QSerialPort::readyRead, 0, 0);

                // get the command as an ASCII string from the TX text edit box
                if ((bArray[0] == '0')&&(bArray[1] == 'x'))
                {
                    //get hex settings
                    stm32bootloaderDialog::hexFileSettings hexSettings = m_stm32bootloaderDialog->getHexSettings();
                    QString tempChar;
                    tempChar.append((QChar)bArray[2]);
                    tempChar.append((QChar)bArray[3]);
                    // get the HEX value from the ASCII string
                    bool ok;
                    int hex_cmd = tempChar.toInt(&ok, 16);
                    tempChar.clear(); // clear the temp buffer
                    // if cmd is valid, parse it and start comm with device
                    if (!ok)
                        ui->m_console->putData("Command must be in ASCII format.");
                     else
                        m_stm32Interpreter.parseCmd(hex_cmd, hexSettings, m_serial, ui->m_console);

                } // end of: if ((bArray[0] == '0')&&(bArray[1] == 'x'))

                // re-enable asynch mode for the serialport RX
                connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::processData);
            }
            else
            {
                ui->m_console->putData("Command must be in the following format: 0xXX");
            }


            break;
        }
        default:
            break;
    } // end of: switch (p.dataFormat)
}

void MainWindow::updateParsingSettingsFromCheckBox()
{   
    if (ui->asciiFormatCheckbox->isChecked())
    {
        m_parsingSettingsDialog->setParsingSettings(ASCII);
        ui->parsingLabel->setText("parsing: ASCII");
        ui->parsingLabel->setToolTip("Received data is in ASCII format.");
    } 
    else
    {
        m_parsingSettingsDialog->setParsingSettings(RAW_BYTE_FORMAT);
        ui->parsingLabel->setText("parsing: raw bytes");
        ui->parsingLabel->setToolTip("Received bytes are printed as they arrived.");

    }
}

void MainWindow::updateParsingLabelAndCheckbox()
{

    switch (m_parsingSettingsDialog->getDataFormat())
    {
        case ASCII:
        {
            ui->asciiFormatCheckbox->setCheckState(Qt::CheckState::Checked);
            ui->plotCheckBox->setDisabled(0);
            ui->parsingLabel->setText("parsing: ASCII");
            ui->parsingLabel->setToolTip("Received data is in ASCII format.");
            break;
        }
        case RAW_DATA_CHECKSUM:
        {
            ui->asciiFormatCheckbox->setCheckState(Qt::CheckState::Unchecked);
            ui->plotCheckBox->setDisabled(0);
            if (m_parsingSettingsDialog->getNbrBytes() == 1)
            {
                ui->parsingLabel->setText("parsing: [DATA][13][CS]");
                ui->parsingLabel->setToolTip("-data format: [DATA][13][CS]\n-CS = [DATA0]^[13]");
            }
            else if (m_parsingSettingsDialog->getNbrBytes() == 2)
            {
                ui->parsingLabel->setText("parsing: [LSB][MSB][13][CS]");
                ui->parsingLabel->setToolTip("-data format: [LSB][MSB][13][CS]\n-CS = [LSB]^[MSB]^[13])");
            }
            else if (m_parsingSettingsDialog->getNbrBytes() == 4)
            {
                ui->parsingLabel->setText("parsing: [LSB][DATA][DATA][MSB][13][CS]");
                ui->parsingLabel->setToolTip("-data format: [LSB][DATA1][DATA2][MSB][13][CS]\n-CS = [LSB]^[DATA1]^[DATA2]^[MSB]^[13])");
            }
            break;
        }
        case STM32_BOOTLOADER_MODE:
        {
            ui->asciiFormatCheckbox->setCheckState(Qt::CheckState::Unchecked);
            ui->plotCheckBox->setCheckState(Qt::CheckState::Unchecked);
            ui->plotCheckBox->setDisabled(1);
            ui->parsingLabel->setText("parsing: STM32 Bootloader");
            break;
        }
        case RAW_BYTE_FORMAT:
        {
            ui->asciiFormatCheckbox->setCheckState(Qt::CheckState::Unchecked);
            ui->plotCheckBox->setCheckState(Qt::CheckState::Unchecked);
            ui->plotCheckBox->setDisabled(1);
            ui->parsingLabel->setText("parsing: raw bytes");
            ui->parsingLabel->setToolTip("Received bytes are printed as they arrived.");
            break;
        }
    }
}


