import socket

def reverse_dns_lookup(ip_address):
    try:
        domain_name = socket.gethostbyaddr(ip_address)
        return domain_name[0]
    except socket.herror:
        return "Unable to resolve IP to a domain name"

if __name__ == "__main__":
    ip_address = input("Enter an IP address: ")
    domain_name = reverse_dns_lookup(ip_address)
    print(f"IP Address: {ip_address}")
    print(f"Domain Name (URL): {domain_name}")
