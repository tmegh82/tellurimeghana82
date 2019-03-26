$ns [Simulator]

$ns color 1 Red

set $nf [open "out.nam" "w"]
$ns namtrace-all $nf

set $tf [open "out.tr" "w"]
$ns trace-all $tf

proc finish {} {

global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam out.nam
exit 0
}


set $n0 [$ns node]
set $n1 [$ns node]
set $n2 [$ns node]
set $n3 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n0 $n2 1.5Mb 10ms DropTail

$ns queue-limit $n2 $n3 10


set $udp [new Agent /UDP]
$ns attach-agent $n1 $udp
$udp set fid_ 2

set $null [new Agent/NULL]
$ns attach-agent $n3 $null

set $cbr [new Application/Traffic/CBR]
$cbr set type_ CBR
$cbr set packet_size 1000
$cbr set rate_ 1mb
$cbr set random_ false



$ns at 0.5 "$udp start"


set $tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
$tcp set class_ 2

set $sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink

$ns connect $tcp $sink
$tcp ftp fid_ 1

set ftp[new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns at 0.5 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "$finish"
$ns run

set lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4 $n5" 0.5 40ms 		LL Queue/DropTail MAC/802_3 Channel]






set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 2Mb 200ms DropTail 

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
$ns add-agent-trace $tcp 
$ns monitor-agent-trace $tcp

set tcpsink [new Agent/TCPSink]
$ns attach-agent $n1 $tcpsink

$ns connect $tcp $tcpsink

set ftp [new Application/FTP]
$ftp attach-agent $tcp
set $ftp type_ FTP
set $tcp fid_ 1
set $tcp window_ 1
set $tcp maxcwnd_ 1




