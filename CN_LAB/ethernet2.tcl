 
#http://pradeepkrishna007.blogspot.com/2011/09/ns2-lab-programs-7th-sem-cseise.html
#initialisation
set ns [new Simulator]

#open the NAM trace file
set nf [open prog5.nam w]
$ns namtrace-all $nf

#open the trace file
set nd [open  prog.tr  w]
$ns trace-all $nd

#define a finish procedure
proc finish {} {
global ns nf nd
$ns flush-trace
close $nf
close $nd
exec nam prog5.nam &
exit 0
}

#create 6 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
#set n6 [$ns node]

#$ns  $n0 $n1 orient right-down
#$ns  $n0 $n2 orient right
#$ns  $n0 $n3 orient right-up
#$ns  $n0 $n4 orient left-down
#$ns  $n0 $n5 orient left
#$ns  $n0 $n6 orient left-up

#create link between the nodes
set lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4 $n5" 0.5Mb 40ms LL Queue/DropTail MAC/802_3 Channel]

#setup a tcp connection
set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n5 $sink
$ns connect $tcp $sink

#setup a FTP over a tcp connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 1.0 "$ftp start"
$ns at 5.0 "$ftp stop"
$ns at 5.5 "finish"
$ns run



#BEGIN {
#sSize=0;
#startTime = 5.0;
#stopTime = 0.1;
#Tput = 0;
#}
#{
#event = $1;
#time = $2;
#from = $3;
#to = $4;
#pkt = $5;
#size = $6;
#fid = $7;
#src = $8;
#dst = $9;
#seqn = $10;
#pid = $11;
#if (event == "+") {
#if(time < startTime) {
#startTime = time;
#}
#}
#if (event == "r") {
#if(time > stopTime) {
#stopTime = time;
#}
#sSize+=size;
#}
#Tput = (sSize/(stopTime-startTime))*(8/1000);
#printf("%f\t%.2f\n",time,Tput);
#}
#END {
#}

