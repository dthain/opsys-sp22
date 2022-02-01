CSE 30341 - Scheduling Homework
-------------------------------

These problems involve working out a number of diagrams,
so we suggest that you sketch your answers carefully on
paper, and then upload pictures of your paper.

Question 1 - Scheduling Archetypes
----------------------------------

Suppose that you have the following jobs to schedule
in a single-processor operating system:

|      | Arrival Time | Length |
--------------------------
|Job A | 0  | 10 |
|Job B | 5  | 20 |
|Job C | 8  | 5  |
|Job D | 9  | 3  |
|Job E | 10 | 2  |
|Job F | 15 | 8  |

For each of the following scheduling algorithms:

- First Come, First Served
- Shortest Job First (Non-Preemptive)
- Shortest Completion Time First (Preemptive)

Show the following:
- A timeline showing the order in which each job executes.
- The response time and turnaround time of each job.
- The average response time and average turnaround time across all jobs.
- The utilization of the system over the entire schedule.

For each schedule, assume that each context switch takes one time unit,
and that ties are broken in favor of the job that arrived earlier.

Question 2 - Multi Level Feedback Queue
---------------------------------------

Suppose that you have a single processor multi-level-feedback-queue
with three queues with scheduling quanta of 5, 10, and 20 time units.
Each context switch takes one time unit.  (This includes when a single
job changes queues but continues to execute.) Ties are broken in favor of
the job that arrived earlier.

Consider the following three jobs:

- Job A wants to run continuously for 25 time units starting at time 0.
- Starting at time 5, Job B wants to run for 1 time unit, then block for 11 time units, repeating three times.
- Starting at time 18, Job C wants to run continuously for 10 time units

Carefully diagram how the basic MLFQ scheduler would schedule these jobs until all are complete,
including the times of each significant event.  (Assume the basic set of rules given in chapters 8.1-8.2
before the two improvement rules are added.)

Question 3 - Multiprocessor Design
----------------------------------

Describe how you would adapt the single processor MLFQ technique to work with multiple process.
There are several different ways to accomplish this, so justify your approach and describe
the strengths and weaknesses of your design.  Give an example of several jobs running in the
system, and how they would be scheduled.

