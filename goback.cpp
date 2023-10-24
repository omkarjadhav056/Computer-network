GO Back N & Selective Repeat.txt
//Write a program to simulate GO Back N and selective repeat modes of sliding window protocol

#include <iostream>
#include <vector>

using namespace std;

class GoBackN {
public:
    GoBackN(int window_size) : window_size(window_size), next_seq_num(0) {
        buffer.resize(window_size);
        for (int i = 0; i < window_size; i++) {
            buffer[i] = i;
        }
    }

    void send() {
        if (next_seq_num < buffer.size()) {
            cout << "Sending packet with sequence number " << next_seq_num << endl;
            next_seq_num++;
        }
    }

    void receive(int ack) {
        cout << "Received ACK for packet with sequence number " << ack << endl;
        while (!buffer.empty() && buffer.front() <= ack) {
            buffer.erase(buffer.begin());
        }
        send();
    }

private:
    int window_size;
    vector<int> buffer;
    int next_seq_num;
};

int main() {
    int window_size = 4;
    GoBackN protocol(window_size);

    for (int i = 0; i < 10; i++) {
        protocol.send();

        if (i % window_size == 0) {
            // Simulate packet loss and retransmission
            cout << "Packet loss - not receiving ACKs" << endl;
        }

        if (i % window_size == 3) {
            // Simulate receiving an ACK for the 4th packet
            protocol.receive(i);
        }
    }

    return 0;
}
