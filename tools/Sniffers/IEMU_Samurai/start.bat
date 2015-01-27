@echo off
start javaw -Xms512m -Xmx512m -cp ./libs/*;packetsamurai.jar com.iemu.packetsamurai.PacketSamurai
exit