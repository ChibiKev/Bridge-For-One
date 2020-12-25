## Bridge For One
Project for CSC 332 - Operating Systems with Professor Zaid Al-Mashhadni at the City College of New York.
## About The Project
- A single-lane bridge connects the two Vermont villages of North Tunbridge and South Tunbridge. Farmers in the two villages use this bridge to deliver their produce to the neighboring town. The bridge can become deadlocked if a northbound and a southbound farmer get on the bridge at the same time. (Vermont farmers are stubborn and are unable to back up.) Implement a solution using Pthreads that synchronizes the threads access to the output screen and prevents deadlock. In particular, represent northbound and southbound farmers as separate threads (use several threads representing the northbound and southbound farmers). Once a farmer is on the bridge the associated thread will:
  - Print to the screen "North (or South) Tunbridge farmer can cross the bridge" after the thread has granted access to the lock.
  - Print on the screen "North (or South) Tunbridge is traveling on the bridge…” as
  - Sleep for a random period (up to 3 seconds).
  - Print to the screen "North (or South) Tunbridge farmer has left the bridge" before releasing the lock.
- Meanwhile, the other village farmer is waiting for the bridge to be clear. The program screen printout should look like the following:
```
North Tunbridge #1 farmer can cross the bridge
North Tunbridge #1 is traveling on the bridge…
North Tunbridge #1 farmer has left the bridge
```
```
South Tunbridge #1 farmer can cross the bridge
South Tunbridge #1 is traveling on the bridge…
South Tunbridge #1 farmer has left the bridge
```
```
North Tunbridge #2 farmer can cross the bridge
North Tunbridge #2 is traveling on the bridge…
North Tunbridge #2 farmer has left the bridge
```
## Additional Information
- There are comments in the code that illustrates the thought process and exactly what each line of code is doing.
## Ask me about anything
If there are any questions, feel free to ask them [here](https://github.com/ChibiKev/Bridge-For-One/issues).