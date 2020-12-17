set ns [new Simulator]

$ns color 0 red
$ns color 1 blue
$ns color 2 yellow
$ns color 3 green

set n0 [$ns node]
set n1 [$ns node]

set f [open out.tr w]
$ns trace-all $f
set nf [open out.nam w]
$ns namtrace-all $nf

$ns duplex-link $n0 $n1 0.2Mb 200ms DropTail

$ns duplex-link-op $n0 $n1 orient right

$ns queue-limit $n0 $n1 10

set tcp [new Agent/TCP]
$tcp set class_ 2
#change window_size for sliding window
$tcp set window_ 0
$tcp set maxcwnd_ 0
set sink [new Agent/TCPSink]
$ns attach-agent $n0 $tcp
$ns attach-agent $n1 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns at 0.4 "$ftp start"
$ns at 2.0 "$ns detach-agent $n0 $tcp ;$ns detach-agent $n1 $sink "


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