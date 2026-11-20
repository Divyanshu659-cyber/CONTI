#include "contiki.h"
#include "net/ipv6/simple-udp.h"
#include "net/ipv6/uip.h"
#include <stdio.h>

#define UDP_PORT 8765
#define UDP_SERVER_PORT 5678

static struct simple_udp_connection udp_conn;
static const char anomaly_message[] = "SIMULATED_ANOMALY";

PROCESS(attacker_process, "Simulated Attacker Node");
AUTOSTART_PROCESSES(&attacker_process);

PROCESS_THREAD(attacker_process, ev, data)
{
  static struct etimer timer;
  static uip_ipaddr_t destination;

  PROCESS_BEGIN();

  if(!simple_udp_register(&udp_conn, UDP_PORT,
                          NULL, UDP_SERVER_PORT, NULL)) {
    printf("ATTACKER: Failed to register UDP connection\n");  }

  uip_create_linklocal_allnodes_mcast(&destination);

  etimer_set(&timer, CLOCK_SECOND * 5);

  while(1) {

    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));

    simple_udp_sendto(&udp_conn,
                      anomaly_message,
                      sizeof(anomaly_message) - 1,
                      &destination);

    printf("ATTACKER: Simulated abnormal packet\n");

    etimer_set(&timer, CLOCK_SECOND * 2);
  }

  PROCESS_END();
}