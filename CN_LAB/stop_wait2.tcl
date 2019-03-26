set ns [new Simulator]
$ns color 1 Blue

set nf [open out.nam w]
$ns namtrace-all $nf

set tf [open "out2.tr" w]
$ns trace-all $tf

proc finish {} {
	global ns nf tf
	$ns flush-trace
	close $nf
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]

$ns at 0.0 "$n0 label Sender"
$ns at 0.0 "$n1 label Receiver"

$ns duplex-link $n0 $n1 1Mb 200ms DropTail
$ns duplex-link-op $n0 $n1 orient down
#$ns queue-limit $n0 $n1 10

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp

$tcp set fid_ 1
$tcp set window_ 1
#Max bound on window size

$tcp set maxcwnd_ 1
#Congestion Window --> Limits max amount of data the tcp can send into the network

$ns add-agent-trace $tcp tcp
$ns monitor-agent-trace $tcp

set tcpsink [new Agent/TCPSink]
$ns attach-agent $n1 $tcpsink
$ns connect $tcp $tcpsink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 0.5 "$ftp start"
$ns at 1.97 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n1 $tcpsink"
$ns at 0.6 "$ns trace-annotate \"send packet 1\""
$ns at 0.799 "$ns trace-annotate \"recieve ack 1\""
$ns at 0.995 "$ns trace-annotate \"send packet 2\""
$ns at 1.191 "$ns trace-annotate \"receive ack 2\""
$ns at 1.389 "$ns trace-annotate \"send packet 3\""
$ns at 1.588 "$ns trace-annotate \"receive ack 3\""
$ns at 1.786 "$ns trace-annotate \"send packet 4\""
$ns at 1.982 "finish"
$ns run






#http://www.mathcs.emory.edu/~cheung/Courses/558-old/Syllabus/90-NS/3-Perf-Anal/TCP-CWND.html
