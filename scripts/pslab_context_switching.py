"""
This script retrieves the context switching time between two tasks.
"""
import serial
import signal
import _thread
import time
import matplotlib.pyplot as plt
import sys
from PSL import sciencelab

BENCH_CONTEXT_SWITCHING_FLAG = '[BENCH_CONTEXT_SWITCHING]' 
SER = serial.Serial('/dev/ttyUSB0', 115200)

I = sciencelab.connect()
VALUES = []
TASKS = {}

def show_results():
    global VALUES
    print()
    print("{} context switchs".format(len(VALUES)))
    print("{} tasks".format(len(TASKS)))
    for key in TASKS:
        print("task {} with {} runs of context switching times".format(key, TASKS[key]))

    for _ in range(int(len(VALUES) * 0.05)):
        VALUES.remove(max(VALUES))  
        VALUES.remove(min(VALUES))
    print("Mean: {} usec".format((sum(VALUES)/len(VALUES))*10**6))
    print("Min {} usec".format(min(VALUES)*10**6))
    print("Max {} usec".format(max(VALUES)*10**6))


    VALUES = sorted(VALUES)
    intervals = []
    dic = {}
    for v in VALUES:
        v = v*10**6
        intervals.append(v)
        dic[v] = dic.get(v, 0) + 1

    print(intervals)
    plt.hist(intervals, bins=3000)
    #plt.bar(dic.keys(), dic.values())
    #plt.axis([10,20,0,500])
    plt.show()

    sys.exit()

def read_uart(threadName):
    while True:
        line = str(SER.readline(), 'utf-8')
        if BENCH_CONTEXT_SWITCHING_FLAG in line:
            if "Start" in line:
                size = int(line.split()[2])
                for _ in range(size):
                    task = str(SER.readline(), 'utf-8').rstrip()
                    TASKS[task] = TASKS.get(task, 0) + 1
        else:
            pass
            #print("[UART] {}".format(line), end="")


ready = False
while not ready:
    try:
        line = str(SER.readline(), 'utf-8')
        #print("[UART] {}".format(line), end="")
        if BENCH_CONTEXT_SWITCHING_FLAG in line:
            if "Ready" in line:
                SER.write(bytes("{} Ready\n".format(BENCH_CONTEXT_SWITCHING_FLAG), 'utf-8'))
                ready = True
    except:
        pass

print('Ready signal received')
_thread.start_new_thread(read_uart, ("READ_UART",))
#signal.signal(signal.SIGINT, hand_inter)

while True:
    CS_TIME = I.MeasureInterval('ID1', 'ID1', 'falling', 'rising')

    if CS_TIME > 0:
        #print(CS_TIME*10**6)
        VALUES.append(CS_TIME)

    if len(VALUES) == 1000 * 1.1:
        show_results()

