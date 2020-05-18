#include "slavethread.h"


/* DEFAULT CONSTRUCTOR) */
SlaveThread::SlaveThread(QObject *parent) :
    QThread(parent)
{
}

/* DESTRUCTOR */
SlaveThread::~SlaveThread()
{
    m_mutex.lock();
    m_quit = true;
    m_mutex.unlock();
    wait();
}

/* START THE THREAD */
void SlaveThread::startSlave(const QString &portName, int waitTimeout)
{
    // 1. Get the MUTEX to protect the serial PORT variables (shared with MAIN WINDOW)
    const QMutexLocker locker(&m_mutex);
    // 2. Update the PORT vvazriables'
    m_portName = portName;
    m_waitTimeout = waitTimeout;
    if (!isRunning())
        start(); // call this thread's run() function
}

/* THREAD'S RUN FUNCTION */
void SlaveThread::run()
{
/* A. Change PORT variables using the mutex (setup, only happens once) */
    bool currentPortNameChanged = false; // flag used so that we connect to the PORT only if it has changed
    // 1. Take the mutex
    m_mutex.lock();
        // 2. Check if the PORT has changed (for re-entrency), if so, update m_portName variable
        QString currentPortName;
        if (currentPortName != m_portName) 
        {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        }
        // 3. update timeout and response variables
        int currentWaitTimeout = m_waitTimeout;
        // 4. Release the mutex
    m_mutex.unlock();


/* B. Infinit loop, if PORT changed, connect to it, attempt reading data from the port, update PORT parameters in case they have been changed in MainWindow */
    QSerialPort serial;
    while (!m_quit)
    {
        // 1. Check if PORT has changed, if so, connect to it
        if (currentPortNameChanged)
        {
            serial.close(); // close all other ports (if no PORT is open, this function can still be called)
            serial.setPortName(currentPortName); // set the serial PORT from our m_currentPort variable

            if (!serial.open(QIODevice::ReadWrite))     // open the PORT, emit the error signal if failed
            {
                emit error(tr("Can't open %1, error code %2")
                           .arg(m_portName).arg(serial.error()));
                return;
            }
        }

        // 2. Check if data is available, if so, read it, timeout after "currentWaitTimeout" msec
        if (serial.waitForReadyRead(currentWaitTimeout))
        {
            QByteArray rxData = serial.readAll(); //get all the bytes available from the PORT
            while (serial.waitForReadyRead(10)) // if more data is coming in within 10msec
                rxData += serial.readAll(); // append it to our byte array "requestData"
            emit data(rxData); // send data to MainWindow
        }

        // 3. Check to see if any of thhe PORT parameters have changed, update it for the next iteration of the while (!m_quit)
        m_mutex.lock(); // take the mutex
            if (currentPortName != m_portName) // if PORT has changed, update it
            {
                currentPortName = m_portName;
                currentPortNameChanged = true;
            }
            else
            {
                currentPortNameChanged = false;
            }
            currentWaitTimeout = m_waitTimeout; // update timeout
        m_mutex.unlock();
    }
}

