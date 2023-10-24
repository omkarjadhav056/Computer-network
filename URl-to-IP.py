import socket

def dns_lookup(url):
    try:
        ip_address = socket.gethostbyname(url)
        return ip_address
    except socket.gaierror:
        return "Unable to resolve URL to an IP address"

if __name__ == "__main__":
    url = input("Enter a URL (e.g., www.example.com): ")
    ip_address = dns_lookup(url)
    print(f"URL: {url}")
    print(f"IP Address: {ip_address}")
