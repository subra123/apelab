from scapy.all import IP, TCP, send

# Spoofed packet settings
src_ip = "1.2.3.4"  # Fake IP
dst_ip = "192.168.1.1"  # Target IP
src_port = 1234
dst_port = 80

# Create IP and TCP headers
ip_layer = IP(src=src_ip, dst=dst_ip)
tcp_layer = TCP(sport=src_port, dport=dst_port, flags="S")  # SYN flag

# Send the spoofed packet
send(ip_layer/tcp_layer, verbose=True)

print("Spoofed TCP SYN packet sent!")
