
#include <iostream>
#include <bitset>


 struct IPv4 {
    uint8_t octet1;
    uint8_t octet2;
    uint8_t octet3;
    uint8_t octet4;
};

 union RawToIP {
     IPv4 ip;
     unsigned int raw;
 };




void setIP(IPv4& ip, uint8_t o1, uint8_t o2, uint8_t o3, uint8_t o4);
void printIP(const IPv4& ip );
uint32_t getRaw(const IPv4& ip);
void getIP(IPv4& ip, uint32_t raw);


 

int main()
{
   IPv4 ip{};
 
   setIP(ip, 192, 168, 0, 33);
   printIP(ip);
   
   std::cout << getRaw(ip) << std::endl;
   uint32_t raw = getRaw(ip);

   IPv4 ip2;
   getIP(ip2, raw);
   printIP(ip2);

}




void setIP(IPv4& ip, uint8_t o1, uint8_t o2, uint8_t o3, uint8_t o4) {
    ip.octet1 = o1;
    ip.octet2 = o2;
    ip.octet3 = o3;
    ip.octet4 = o4;
}

void printIP(const IPv4& ip) {
    printf("%d.%d.%d.%d\n", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}


uint32_t getRaw(const IPv4& ip) {
    RawToIP rwip;
    rwip.ip = ip;
    return rwip.raw;
}

void getIP(IPv4& ip, uint32_t raw) {
    RawToIP rwip;
    rwip.raw = raw;
    ip = rwip.ip;
}