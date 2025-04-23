//Robot Communication Protocol

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // For exception handling
#include <memory> // For smart pointers

using namespace std;

// Enumeration for communication protocols
enum class Protocol {
    UART,
    I2C,
    SPI
};

// Structure for a message
struct Message {
    string content; // Content of the message
    int priority; // Priority of the message

    // Constructor for Message
    Message(const string& c, int p) : content(c), priority(p) {}
};

// Base class for Communication
class Communication {
protected:
    Protocol protocol; // Communication protocol
    vector<Message> messageQueue; // Queue of messages

public:
    // Constructor for Communication
    Communication(Protocol p) : protocol(p) {}

    // Function to send a message
    virtual void sendMessage(const Message& msg) {
        messageQueue.push_back(msg);
        cout << "Sending message: " << msg.content << " with priority: " << msg.priority << endl;
    }

    // Function to receive a message
    virtual Message receiveMessage() {
        if (messageQueue.empty()) {
            throw runtime_error("No messages to receive.");
        }
        Message msg = messageQueue.back(); // Get the last message
        messageQueue.pop_back(); // Remove it from the queue
        cout << "Receiving message: " << msg.content << " with priority: " << msg.priority << endl;
        return msg;
    }

    // Function to display the communication protocol
    void displayProtocol() const {
        cout << "Current Protocol: " << getProtocolString(protocol) << endl;
    }

    // Function to get string representation of the protocol
    string getProtocolString(Protocol p) const {
        switch (p) {
            case Protocol::UART: return "UART";
            case Protocol::I2C: return "I2C";
            case Protocol::SPI: return "SPI";
            default: return "Unknown";
        }
    }

    // Virtual destructor
    virtual ~Communication() {}
};

// Derived class for UART Communication
class UARTCommunication : public Communication {
public:
    // Constructor for UARTCommunication
    UARTCommunication() : Communication(Protocol::UART) {}

    // Overriding sendMessage to include UART-specific behavior
    void sendMessage(const Message& msg) override {
        cout << "UART Protocol: ";
        Communication::sendMessage(msg);
    }
};

// Derived class for I2C Communication
class I2CCommunication : public Communication {
public:
    // Constructor for I2CCommunication
    I2CCommunication() : Communication(Protocol::I2C) {}

    // Overriding sendMessage to include I2C-specific behavior
    void sendMessage(const Message& msg) override {
        cout << "I2C Protocol: ";
        Communication::sendMessage(msg);
    }
};

// Derived class for SPI Communication
class SPICommunication : public Communication {
public:
    // Constructor for SPICommunication
    SPICommunication() : Communication(Protocol::SPI) {}

    // Overriding sendMessage to include SPI-specific behavior
    void sendMessage(const Message& msg) override {
        cout << "SPI Protocol: ";
        Communication::sendMessage(msg);
    }
};

// Class for Robot
class Robot {
private:
    string name; // Name of the robot
    unique_ptr<Communication> comm; // Communication protocol

public:
    // Constructor for Robot
    Robot(const string& n, unique_ptr<Communication> c) 
        : name(n), comm(move(c)) {}

    // Function to send a message
    void sendMessage(const string& content, int priority) {
        Message msg(content, priority);
        comm->sendMessage(msg);
    }

    // Function to receive a message
    void receiveMessage() {
        try {
            comm->receiveMessage();
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    // Function to display robot status
    void displayStatus() const {
        cout << "Robot Name: " << name << endl;
        comm->displayProtocol();
    }
};

int main() {
    // Create a robot with UART communication
    Robot robot1("Robot1", make_unique<UARTCommunication>());
    robot1.displayStatus();
    robot1.sendMessage("Hello from Robot1", 1);
    robot1.receiveMessage();

    cout << endl;

    // Create a robot with I2C communication
    Robot robot2("Robot2", make_unique<I2CCommunication>());
    robot2.displayStatus();
    robot2.sendMessage("Hello from Robot2", 2);
    robot2.receiveMessage();

    cout << endl;

    // Create a robot with SPI communication
    Robot robot3("Robot3", make_unique<SPICommunication>());
    robot3.displayStatus();
    robot3.sendMessage("Hello from Robot3", 3);
    robot3.receiveMessage();

    return 0; // End of the program
}