#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("COM Port"));

    /* CREATE OBJECTS ON THJE HEAP */
    m_comPortLabel =  new QLabel("Serial port:", this);
    m_serialPortComboBox = new QComboBox(this);
    m_connectButton = new QPushButton("Connect", this);
    m_disconnectButton = new QPushButton("Disconnect", this);
    m_clearTextButton = new QPushButton("Clear", this);
    m_comStatusLabel =  new QLabel("Not connected.", this);
    m_rxDataLabel =  new QLabel("RX data:", this);
    m_serial = new QSerialPort(this);
    m_autoscrollCheckBox = new QCheckBox("Auto-scroll", this);
    m_autoscrollCheckBox->setChecked(true);

    /* text box for received data */
    m_rxDataPlainTextEdit = new QPlainTextEdit(this);
    m_rxDataPlainTextEdit->document()->setMaximumBlockCount(1000);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    m_rxDataPlainTextEdit->setPalette(p);
    m_rxDataPlainTextEdit->setReadOnly(true);

    /* SET LAYOUT */
    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(m_comPortLabel, 0, 0);
    mainLayout->addWidget(m_serialPortComboBox, 0, 1);
    mainLayout->addWidget(m_connectButton, 0, 2);
    mainLayout->addWidget(m_disconnectButton, 1, 2);
    mainLayout->addWidget(m_clearTextButton, 2, 2);
    mainLayout->addWidget(m_comStatusLabel, 2, 0);
    mainLayout->addWidget(m_rxDataLabel, 3, 0);
    mainLayout->addWidget(m_autoscrollCheckBox, 3, 2);
    mainLayout->addWidget(m_rxDataPlainTextEdit, 3, 1);
    QWidget * widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
    setLayout(mainLayout);

    /* POPULATE COMBO BOX WITH AVAILABLE COM PORTS */
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        m_serialPortComboBox->addItem(info.portName());

    /* CONNECT INPUTS AND FUNCTIONS */
    connect(m_connectButton, &QPushButton::clicked, this, &MainWindow::connectToPort);
    connect(m_disconnectButton, &QPushButton::clicked, this, &MainWindow::disconnectToPort);
    connect(m_clearTextButton, &QPushButton::clicked, this, &MainWindow::clearTextEdit);
    connect(m_autoscrollCheckBox, &QCheckBox::stateChanged, this, &MainWindow::changeScrolling);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::processData);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToPort()
{
    m_serial->close(); // close all other ports (if no PORT is open, this function can still be called)
    m_serial->setPortName(m_serialPortComboBox->currentText());
    m_serial->setBaudRate(QSerialPort::Baud115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (!m_serial->open(QIODevice::ReadWrite))     // open the PORT, emit the error signal if failed
    {
        m_comStatusLabel->setText(tr("Can't open %1, error code %2")
                   .arg(m_serial->portName()).arg(m_serial->error()));
        return;
    }
    else
    {
        m_comStatusLabel->setText(tr("Connected to %1.")
                   .arg(m_serialPortComboBox->currentText()));
    }
}

void MainWindow::disconnectToPort()
{
    m_serial->close(); // close all other ports (if no PORT is open, this function can still be called)
    m_comStatusLabel->setText(tr("Not connected."));
}


void MainWindow::processTimeout(const QString &s)
{
    m_comStatusLabel->setText(tr("Timeout on port %1.").arg(s));
}

void MainWindow::processData()
{
    QString rxData = m_serial->readAll();
    m_rxDataPlainTextEdit->insertPlainText(rxData);

    if ((rxData[0] == "2") && (rxData[1] == "0"))
    {
        m_rxDataPlainTextEdit->insertPlainText("Glenda sucks \n");
    }

    if (autoScroll)
    {
        QScrollBar *bar = m_rxDataPlainTextEdit->verticalScrollBar();
        bar->setValue(bar->maximum());
    }
}

void MainWindow::clearTextEdit()
{
    m_rxDataPlainTextEdit->clear();
}

void MainWindow::changeScrolling()
{
    if (m_autoscrollCheckBox->isChecked())
    {
        autoScroll = 1;
    }
    else
    {
        autoScroll = 0;
    }
}
