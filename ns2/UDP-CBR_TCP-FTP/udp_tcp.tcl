set ns [new Simulator]

$ns color 0 red
$ns color 1 blue
$ns color 2 yellow
$ns color 3 green

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf

$ns duplex-link $n0 $n2 5Mb 2ms DropTail
$ns duplex-link $n1 $n2 5Mb 2ms DropTail
$ns duplex-link $n2 $n3 1.5Mb 10ms DropTail
$ns duplex-link $n2 $n5 1.5Mb 10ms DropTail
$ns duplex-link $n3 $n4 1.5Mb 10ms DropTail

$ns duplex-link-op $n0 $n2 orient right-up
$ns duplex-link-op $n1 $n2 orient right-down
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n2 $n5 orient right-down
$ns duplex-link-op $n3 $n4 orient up

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

set udp1 [new Agent/UDP]
$ns attach-agent $n3 $udp1
$udp1 set class_ 1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1

set udp2 [new Agent/UDP]
$ns attach-agent $n2 $udp2
set cbr2 [new Application/Traffic/CBR]
$cbr2 attach-agent $udp2

set null0 [new Agent/Null]
$ns attach-agent $n3 $null0

set null1 [new Agent/Null]
$ns attach-agent $n1 $null1

set null2 [new Agent/Null]
$ns attach-agent $n5 $null2

$ns connect $udp0 $null0
$ns connect $udp1 $null1
$ns connect $udp2 $null2

$ns at 1.0 "$cbr0 start"
$ns at 1.05 "$ns trace-annotate \"Send Packet1\""
$ns at 1.1 "$cbr1 start"
$ns at 1.15 "$ns trace-annotate \"Send Packet2\""
$ns at 1.2 "$cbr2 start"
$ns at 1.25 "$ns trace-annotate \"Send Packet3\""

set tcp [new Agent/TCP]
$tcp set class_ 2
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $tcp
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns at 1.4 "$ftp start"
$ns at 1.6 "$ns detach-agent $n1 $tcp ;$ns detach-agent $n4 $sink "
puts [$cbr0 set packetSize_]
puts [$cbr0 set interval_]

$ns at 3.0 "finish"

proc finish {} {
    global f nf ns
    $ns flush-trace
    close $f
    close $nf
    puts "running nam.."
    exec nam out.nam &
    exit 0

}


$ns run