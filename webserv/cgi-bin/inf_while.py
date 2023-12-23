import time
import os
duration = 1000  # milliseconds
freq = 440  # Hz

if __name__ == "__main__":
    print("Content-Type: text/html")    # HTML is following
    print()                             # blank line, end of headers

    for i in range(10):
        print("hello2")
        os.system('play -nq -t alsa synth {} sine {}'.format(duration, freq)) 
        time.sleep(1)
