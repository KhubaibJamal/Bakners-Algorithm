 DEADLOCK:
 Introduction:

Deadlock is a situation where a set of processes are blocked because each processes holding a resource acquired by some other process.
Consider an example when two train area coming towards each other on the same track and there is only one track, none of the trains can move once they are in front of each other. A similar situation occurs in operating system when there are two or more processes the hold same resources and wait for resources held by others. for example, in the blow diagram, Process 1 is holding resource 1 and waiting resource 2 which is acquires by process 2, and process 2 is waiting for resource 1.
 
Deadlock car arise if the following four conditions hold simultaneously (necessary conditions).
Mutual Exclusion: Two or more resources area non-sharable (only one process can use at a time).
Hold and Wait: A process is holding at least one resource and waiting for resources
No Preemption: A resource cannot be taken from a process unless the process releases the resources.
Circular Wait: A set of processes area waiting for each other in circular form.

 
BANKER’S ALGORITHM:
It is a banker algorithm used to avoid deadlock and allocate resources safely to each process in the computer system. The 'S-State' examines all possible tests or activities before deciding whether the allocation should be allowed to each process. It also helps the operating system to successfully share the resources between all the processes. The banker's algorithm is named because it checks whether a person should be sanctioned a loan amount or not to help the bank system safely simulate allocation resources. In this section, we will learn the Banker's Algorithm in detail. Also, we will solve problems based on the Banker's Algorithm. To understand the Banker's Algorithm first we will see a real word example of it.
It works in an Operating System When a new process is created in a computer system, the process must provide all types of information to the operating system like upcoming processes, requests for their resources, counting them, and delays. Based on these criteria, the operating system decides which process sequence should be executed or waited so that no deadlock occurs in a system. Therefore, it is also known as deadlock avoidance algorithm or deadlock detection in the operating system.
