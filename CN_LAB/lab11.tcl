set ns [new Simulator]

#$ns color 1 Red
$ns color 1 Red

set nf [open "out.nam" w]
$ns namtrace-all $nf

set tf [open "out.tr" w]
$ns trace-all $tf

proc finish {} {

	global ns nf tf
	$ns flush-trace
	close $nf
	close $tf
	exec nam out.nam &
	exit 0
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.5Mb 20ms DropTail

$ns queue-limit $n2 $n3 10


$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

$ns duplex-link-op $n2 $n3 queuePos 0.5

set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink

$ns connect $tcp $sink
$tcp set fid_ 1


set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

$ns at 0.5 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "finish"
$ns run


