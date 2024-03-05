This little program is made for counting amount of transfered packs and bytes through every unique `threads`

`"Thread"` is a combination of `unique source IP address, unique destination IP address, unique source Port and unique destination Port`

It compiles in an .exe file that takes path string to your .pcap file as a cmd argument
It prints unique threads and transfered bytes and then saves all the information (with counted packs sent through threads) to .csv file 

Works only with IPv4 (more soon maybe...)

__NpCap is needed!__

Launching:
![scr2](https://github.com/QuiteHorn/Pcap-IPv4-Reader/assets/63408009/8461b643-c3c3-491c-8413-43a6c8dd4e64)

Wireshark screenshot with output:
![scr1](https://github.com/QuiteHorn/Pcap-IPv4-Reader/assets/63408009/4660dff3-a970-438d-95c0-dcb5a35db8a6)

.csv file:

![scr3](https://github.com/QuiteHorn/Pcap-IPv4-Reader/assets/63408009/f9a6ce94-79fa-4516-88d9-adae068c4981)
