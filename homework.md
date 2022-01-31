# CSE 30341 - Synchronization Homework

Background
----------

As we discussed in class, a monitor is a code-organization strategy for writing safe concurrent programs.
A monitor consists of a data structure, a mutex, a condition variable,
and one or more methods to manipulate the data structure.
Each method must lock/unlock the mutex, and may wait for or wakeup other threads.

Concurrent programming is trickier than it first appears:
it is all too easy to write a program that appears to be correct, but has a subtle bug.
Here is a foolproof recipe to write simple and correct monitor code:

- Always lock/unlock at the beginning/end of each method.
- Broadcast whenever a covering condition is triggered.
- After sleeping, consider the wakeup as a hint that your condition might be satisfied. Check to be sure. 

The Bank Account Problem
------------------------

Suppose you have an integer representing your balance at the bank.
Multiple threads may deposit or withdraw money from the account.
If a withdrawal would cause the balance to fall below zero,
then the withdrawal should block until it can be satisfied by a deposit.

For example, here is the foolproof solution to the bank-account problem that we arrived on in class:

```
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int balance = 0;

void deposit( int amount )
{
	pthread_mutex_lock(&mutex);
	balance += amount;
	pthread_cond_broadcast(&cond);
	pthread_mutex_unlock(&mutex);
}

void withdraw( int amount )
{
	pthread_mutex_lock(&mutex);
	while(balance<amount) {
		pthread_cond_wait(&cond,&mutex);
	}
	balance -= amount;
	pthread_mutex_lock(&mutex);
}
```

**Question 1:** It is tempting to pursue more complex solutions to the bank-account problem.
For example, we can try to make the solution more efficient by using the "punch your neighbor"
discussed in class and given below. However, this approach does not work correctly. Explain why.

```
/* The Punch Your Neighbor Solution */

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int balance = 0;

void deposit( int amount )
{
	pthread_mutex_lock(&mutex);
	balance += amount;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
}

void withdraw( int amount )
{
	pthread_mutex_lock(&mutex);
	while(balance<amount) {
		pthread_cond_wait(&cond,&mutex);
		if(balance<amount) {
			pthread_cond_signal(&cond);
		}
	}
	balance -= amount;
	pthread_mutex_unlock(&mutex);
}
```

**Question 2.** Can the punch-your-neighbor approach be fixed by a small code change? If so, give it. If not, explain why not.

The Readers-Writers Problem
---------------------------

There are many threads accessing a shared data structure repeatedly.
Sometimes threads want to write the data structure,
other times they want to read it.
It is safe to allow multiple reader threads in simultaneously,
but a writer thread may only enter by itself.
You may assume each thread runs in a loop like this:

```
while(1) {
   if( coin flip ) {
       read_lock();
       // read the data structure
       read_unlock();
   } else {
       write_lock();
       // write the data structure
       write_unlock();
   }
}
```

**Question 3** - Solve the readers-writers problem using the foolproof approach described above. Use the following code structure:

```
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Add more global variables if you like.

void read_lock()
{
}

void read_unlock()
{
}

void write_lock()
{
}

void write_unlock()
{
}
```

**Question 4** - The foolproof approach is safe, but may potentially cause starvation
if reader threads continually arrive, preventing the writer thread from obtaining the lock.
Write a slightly more complex solution that prevents starvation but still provides the same level of safety.
(Use the same code structure as above.)

Santa's Elves Problem
---------------------

Santa Claus has a large number of elves building toys.
Occasionally they run into problems and need advice from Santa.
However, they don't want to waste Santa's valuable time,
so they wait until three elves all have a problem,
and then all three go into Santa's workshop to ask their questions.
Exactly three elves may enter together, and no more may enter until all three leave.

**Question 5** Write a solution to the Santa's Elves problem, starting with the foolproof approach described above.

*Be careful:* This problem is not as easy as it first appears! Consider what happens if there are lots of threads, and many elves want to ask questions at once?
You can imagine each elf is a thread that looks like this:

```
void elf()
{
    while(1) {
        // Work on toys for a while
        wait_for_three_elves();
        // Ask Santa a question.
        done_asking();
    }
}
```

Now write some code like this:

```
pthread_mutex_t mutex;
pthread_cond_t cond;

// Add global variables here

void wait_for_three_elves()
{
...
}

void done_asking()
{
...
}
```

Turning In
----------

Please type up your answers in a nicely formatted document, and submit via Canvas.
