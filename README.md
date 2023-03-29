# UDP Packet Radio Transmitter

This is a simple UDP packet radio transmitter that can be used to send packets over a radio link. The transmitter is implemented in C and uses the UDP protocol to send packets.

## Building and Running

To build the transmitter, simply run the following command:

make

This will compile the transmitter and create an executable file named `udp`.

To run the transmitter, you need to specify the following parameters:

- IP address of the receiver
- Port number of the receiver
- Radio frequency (in Hz)
- Sampling rate (in Hz)
- Bit rate (in bits per second)
- Payload size (in bytes)
- Number of packets to transmit

For example, to transmit 100 packets with a payload size of 512 bytes at a bit rate of 1 Mbps over a radio link with a frequency of 433 MHz and a sampling rate of 1 MHz to a receiver with an IP address of 192.168.1.100 and a port number of 12345, you would run the following command:

./udp 192.168.1.100 12345 433000000 1000000 1000000 512 100

## Protocol

The transmitter uses the following protocol to send packets:

1. The transmitter reads a payload from standard input.
2. The payload is divided into packets of the specified size.
3. Each packet is encoded using Manchester encoding to ensure that there are no long runs of 0s or 1s.
4. The encoded packet is modulated using frequency shift keying (FSK) to transmit the data over the radio link.
5. The receiver receives the modulated signal, demodulates it using FSK, decodes the packet using Manchester encoding, and reassembles the payload.

## License

This software is released under the MIT License. 
