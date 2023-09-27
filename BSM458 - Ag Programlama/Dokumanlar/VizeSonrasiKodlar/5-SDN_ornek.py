#!/usr/bin/python

try:
    import sys
    import os
    #import MySQLdb
    from mininet.net import Mininet
    from mininet.node import Controller, RemoteController, OVSKernelSwitch, UserSwitch
    from mininet.cli import CLI
    from mininet.log import setLogLevel, info
    from mininet.link import Link, TCLink
    from time import sleep

except ImportError, err:
    import sys
    print >> sys.stderr, err
    sys.exit(1)


def deneme():

    kavsak_id = 1


    n=6
    CONTROLLER_IP='192.168.30.133'

    net = Mininet( controller=RemoteController, link=TCLink, switch=OVSKernelSwitch )

    c0= net.addController( 'c0',
                      controller=RemoteController,
                      ip=CONTROLLER_IP )   

    #Switchleri tanimlama

    yenicami_sw = net.addSwitch( 's1', mac='00:00:00:00:00:01' )
    bulvar_sw = net.addSwitch( 's2', mac='00:00:00:00:00:02' )
    orhancami_sw = net.addSwitch( 's3', mac='00:00:00:00:00:03' )
    gecit_sw = net.addSwitch( 's4', mac='00:00:00:00:00:04' )
    askeriye_sw = net.addSwitch( 's5', mac='00:00:00:00:00:05' )
    hastane_sw = net.addSwitch( 's6', mac='00:00:00:00:00:06' )
    sgk_sw = net.addSwitch( 's7', mac='00:00:00:00:00:07' )
    merkez_sw = net.addSwitch( 's8', mac='00:00:00:00:00:08' )	

    host = net.addHost('fuzzymodel', mac='00:00:00:00:00:82', ip='10.0.0.82' )
    net.addLink(host, merkez_sw)



    #Her switch icin 6 host olusturma ve ilgili switche baglama



    for a in range(n):
            host = net.addHost('yenicami%s' % (a + 1), mac='00:00:00:00:00:1%s' % (a + 1), ip='10.0.0.1%s/8' % (a + 1) )
            net.addLink(host, yenicami_sw)

    for a in range(n):
            host = net.addHost('orhancami%s' % (a + 1), mac='00:00:00:00:00:2%s' % (a + 1), ip='10.0.0.2%s/8' % (a + 1) )
            net.addLink(host, bulvar_sw)

    for a in range(n):
            host = net.addHost('bulvar%s' % (a + 1), mac='00:00:00:00:00:3%s' % (a + 1), ip='10.0.0.3%s/8' % (a + 1) )
            net.addLink(host, orhancami_sw)

    for a in range(n):
            host = net.addHost('gecit%s' % (a + 1), mac='00:00:00:00:00:4%s' % (a + 1), ip='10.0.0.4%s/8' % (a + 1) )
            net.addLink(host, gecit_sw)  

    for a in range(n):
            host = net.addHost('askeriye%s' % (a + 1), mac='00:00:00:00:00:5%s' % (a + 1), ip='10.0.0.5%s/8' % (a + 1) )
            net.addLink(host, askeriye_sw)

    for a in range(n):
            host = net.addHost('sgk%s' % (a + 1), mac='00:00:00:00:00:6%s' % (a + 1), ip='10.0.0.6%s/8' % (a + 1) )
            net.addLink(host, hastane_sw)

    for a in range(n):
            host = net.addHost('hastane%s' % (a + 1), mac='00:00:00:00:00:7%s' % (a + 1), ip='10.0.0.7%s/8' % (a + 1) )
            net.addLink(host, sgk_sw)

    #h1 = net.get('h1')
    net.addLink(merkez_sw, yenicami_sw)
    net.addLink(merkez_sw, bulvar_sw)
    net.addLink(merkez_sw, orhancami_sw)
    net.addLink(yenicami_sw, bulvar_sw)
    net.addLink(yenicami_sw, gecit_sw)
    net.addLink(yenicami_sw, hastane_sw)
    net.addLink(orhancami_sw, bulvar_sw)
    net.addLink(orhancami_sw, gecit_sw)
    net.addLink(bulvar_sw, gecit_sw)
    net.addLink(gecit_sw, askeriye_sw)
    net.addLink(askeriye_sw, hastane_sw)
    net.addLink(askeriye_sw, sgk_sw)
    net.addLink(hastane_sw, sgk_sw) 

    #try: 
        #for line in open('/home/musa/simple.tr', 'r'):
        	#db._insert_data(kavsak_id, line)
    #except Exception, err:
    	#print >> sys.stderr, err
    #vsys.exit(1)

    #db._close_db()


    net.build()

    #Switchleri kontrolurda baslatma

    yenicami_sw.start( [c0] )
    bulvar_sw.start( [c0] )
    orhancami_sw.start( [c0] )
    gecit_sw.start( [c0] )
    askeriye_sw.start( [c0] )
    hastane_sw.start( [c0] )
    sgk_sw.start( [c0] )
    merkez_sw.start( [c0] )

 
    c0.start()
   
    #h1.cmdPrint('python Desktop/parser.py Desktop/makale/500/output-tripinfos_500.xml h1-eth0')
    #h1.cmd('sleep 5')
  	
    CLI( net )
    net.stop()



if __name__ == '__main__':
    setLogLevel( 'info' )
    deneme()
