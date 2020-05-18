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
    m_refreshButton = new QPushButton("Refresh", this);
    m_comStatusLabel =  new QLabel("Not connected.", this);
    m_rxDataLabel =  new QLabel("RX data:", this);
    m_rxDataLineEdit = new QLineEdit("No data.", this);

    /* SET LAYOUT */
    auto mainLayout = new QGridLayout;
    mainLayout->addWidget(m_comPortLabel, 0, 0);
    mainLayout->addWidget(m_serialPortComboBox, 0, 1);
    mainLayout->addWidget(m_connectButton, 0, 2);
    mainLayout->addWidget(m_refreshButton, 1, 2);
    mainLayout->addWidget(m_comStatusLabel, 2, 0);
    mainLayout->addWidget(m_rxDataLabel, 3, 0);
    mainLayout->addWidget(m_rxDataLineEdit, 3, 1);
    QWidget * widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);
    setLayout(mainLayout);

    /* POPULATE COMBO BOX WITH AVAILABLE COM PORTS */
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        m_serialPortComboBox->addItem(info.portName());

    /* CONNECT INPUTS AND FUNCTIONS */
    connect(m_connectButton, &QPushButton::clicked, this, &MainWindow::startSlave); 
    connect(&m_thread, &SlaveThread::error, this, &MainWindow::processError);
    connect(&m_thread, &SlaveThread::timeout, this, &MainWindow::processTimeout);
    connect(&m_thread, &SlaveThread::data, this, &MainWindow::processData);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSlave()
{
    m_comStatusLabel->setText(tr("Connected to port %1.")
                           .arg(m_serialPortComboBox->currentText()));
    m_thread.startSlave(m_serialPortComboBox->currentText(), 1000);
}

void MainWindow::processError(const QString &s)
{
    m_comStatusLabel->setText(s);
}

void MainWindow::processTimeout(const QString &s)
{
    m_comStatusLabel->setText(tr("Timeout on port %1.").arg(s));
}

void MainWindow::processData(QByteArray dataArray)
{
    // print data as a string
    const QString rxData = QString::fromUtf8(dataArray);
    m_rxDataLineEdit->setText(rxData);
}

