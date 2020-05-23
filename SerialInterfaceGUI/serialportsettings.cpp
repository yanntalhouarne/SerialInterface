#include "serialportsettings.h"
#include "ui_portSettingsDialog.h"

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

serialPortSettingsDialog::serialPortSettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::portSettingsDialog)
{
    ui->setupUi(this);

    connect(ui->ApplyButton, &QPushButton::clicked,
            this, &serialPortSettingsDialog::apply);
    connect(ui->serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &serialPortSettingsDialog::showPortInfo);

    fillPortsParameters();
    fillPortsInfo();

    updateSettings();
}

/* DESTRUCTOR */
serialPortSettingsDialog::~serialPortSettingsDialog()
{
    delete ui;
}

/* UPDATE SERIAL PORT SELECT BOX INFO */
void serialPortSettingsDialog::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    // get a list of the paramters of the port comboBox
    const QStringList list = ui->serialPortInfoListBox->itemData(idx).toStringList();

    ui->descriptionLabel->setText(tr("Description: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    ui->manufacturerLabel->setText(tr("Manufacturer: %1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    ui->serialNumberLabel->setText(tr("Serial number: %1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    ui->locationLabel->setText(tr("Location: %1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    ui->vidLabel->setText(tr("Vendor Identifier: %1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    ui->pidLabel->setText(tr("Product Identifier: %1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));
}


void serialPortSettingsDialog::fillPortsInfo()
{
    // serialPortInfoListBox is a combo box that holds lists containing information about the available COM ports
    ui->serialPortInfoListBox->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description(); // get description string
        manufacturer = info.manufacturer(); // get manufacturer string
        serialNumber = info.serialNumber(); // get serial number string
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortInfoListBox->addItem(list.first(), list);
    }

    //ui->serialPortInfoListBox->addItem(tr("Custom"));
}

/* POPULATE COMBO BOXES IN SERIAL PORT PARAMETERS BOX */
void serialPortSettingsDialog::fillPortsParameters()
{
    ui->baudRateBox->addItem(QStringLiteral("1200"), QSerialPort::Baud1200);
    ui->baudRateBox->addItem(QStringLiteral("2400"), QSerialPort::Baud2400);
    ui->baudRateBox->addItem(QStringLiteral("4800"), QSerialPort::Baud4800);
    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->setCurrentIndex(6); // default is 115200
    //ui->baudRateBox->addItem(tr("Custom"));


    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3); // defualt is 8

    ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);
    ui->parityBox->setCurrentIndex(0); // default is no parity


    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    #ifdef Q_OS_WIN // only on windowsS
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
    #endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
    ui->stopBitsBox->setCurrentIndex(0); // default is one stop

    ui->flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
    ui->flowControlBox->setCurrentIndex(0); // default is no no flow control
}

/* GET CURRENT SETTINGS CLASS */
serialPortSettingsDialog::Settings serialPortSettingsDialog::settings() const
{
    return m_currentSettings;
}

/* UPDATE CURRENT SETTINGS FROM PORT SETTIGNS DIALOG COMBOBOXES */
void serialPortSettingsDialog::updateSettings()
{
    //m_currentSettings.name = ui->serialPortInfoListBox->currentText();

//    if (ui->baudRateBox->currentIndex() == 4) {
//        m_currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
//    } else {
    m_currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
  //  }
    m_currentSettings.stringBaudRate = QString::number(m_currentSettings.baudRate);

    m_currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
    m_currentSettings.stringDataBits = ui->dataBitsBox->currentText();

    m_currentSettings.parity = static_cast<QSerialPort::Parity>(
                ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
    m_currentSettings.stringParity = ui->parityBox->currentText();

    m_currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
    m_currentSettings.stringStopBits = ui->stopBitsBox->currentText();

    m_currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                ui->flowControlBox->itemData(ui->flowControlBox->currentIndex()).toInt());
    m_currentSettings.stringFlowControl = ui->flowControlBox->currentText();

//   / m_currentSettings.localEchoEnabled = ui->localEchoCheckBox->isChecked();
}

/* APPLPY SLOT */
void serialPortSettingsDialog::apply()
{
    updateSettings();
    hide();
}

/* SET DEFAULT SETTINGS */
void serialPortSettingsDialog::setDefault()
{
    m_currentSettings.baudRate = QSerialPort::Baud115200;
    m_currentSettings.dataBits = QSerialPort::Data8;
    m_currentSettings.parity = QSerialPort::NoParity;
    m_currentSettings.stopBits = QSerialPort::OneStop;
    m_currentSettings.flowControl = QSerialPort::NoFlowControl;
}

/* SET PORT NAME */
void serialPortSettingsDialog::setPort(QString portName)
{
    m_currentSettings.name = portName;
}

/* GET CURRENT SETTINGS MEMBERS */
QString serialPortSettingsDialog::getCurrentName()
{
    return m_currentSettings.name;
}
qint32 serialPortSettingsDialog::getCurrentBaudRate()
{
    return m_currentSettings.baudRate;
}
QSerialPort::DataBits serialPortSettingsDialog::getCurrentDatabits()
{
    return m_currentSettings.dataBits;
}
QSerialPort::Parity serialPortSettingsDialog::getCurrentParity()
{
    return m_currentSettings.parity;
}
QSerialPort::StopBits serialPortSettingsDialog::getCurrentStopBits()
{
    return m_currentSettings.stopBits;
}
QSerialPort::FlowControl serialPortSettingsDialog::getCurrentFLowControl()
{
    return m_currentSettings.flowControl;
}
