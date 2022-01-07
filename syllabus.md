CSE 30341-01, Spring 2020
Operating Systems Principles
University of Notre Dame
Prof. Douglas Thain (dthain@nd.edu)

Overview

An operating system (OS) is a layer of software that manages hardware resources and that provides user programs with a simple and consistent interface to the machine. In this course, we will examine the services and abstractions commonly provided by operating systems, and we will study the underlying mechanisms used to implement them. Topics include processes and threads, synchronization, cpu scheduling, deadlocks, memory management, segmentation and paging systems, storage and file systems, distributed systems, and virtualization.
A good understanding of OS internals offers several benefits, whether you intend to work in computer hardware or computer software. First, by understanding how an OS works, you will be able to write better software applications by making efficient use of OS abstractions such as filesystems and memory allocators. Second, the traditional problems that occur in operating systems (like scheduling, synchronization, and resource management) also occur in all sorts of other systems, ranging from small embedded computers to large scale cloud computing systems. The techniques that you learn here will have applications in any complex computer system.

The concepts presented in class will be explored through a series of six intensive programming assignments. The assignments will make use of the C programming language, which the universal language for implementing and accessing operating systems at the lowest level. The projects will give students ample practice in manipulating pointers, managing memory, invoking system services, and dealing with error conditions. Although we will offer some technical guidance on these matters, students should expect to spend significant time debugging, consulting reference materials, and revising the projects until they work properly.

The goals for each student in this course are:

To understand the abstractions and services provided by an operating system.
To understand the mechanisms and algorithms used to implement these services
To get practical experience using and implementing operating system services.
The course materials will test each student's achievement of these goals at several levels. For each topic in the course, students must be able to:

Describe traditional operating system structures and algorithms.
Demonstrate in detail how they apply to various programs and data.
Evaluate the strengths and weaknesses of related structures and algorithms.
Propose and evaluate a variety of improvements upon traditional methods.
Implement basic methods in a working computing system.
Course Communications

The course web page contains the schedule, assignments, and other critical information:
http://www.nd.edu/~dthain/courses/cse30341/spring2020
Sakai will be used only to record and distribute grades:
http://sakai.nd.edu

Piazza will be used for general Q&A about assignments. You are welcome to post or answer questions at any time; the instructors will generally answer questions on weekday afternoons: https://piazza.com/class/k55khced8f06f5

Textbooks

Required: Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau, Operating Systems in Three Easy Pieces, Arpaci-Dusseau Books, 2019. (http://ostep.org)
Suggested Reference: Kernighan and Ritchie, The C Programming Language, Prentice-Hall, 1988.
Reading Assignments

Please read the assigned chapters the weekend preceding the corresponding lecture. To encourage you to read the textbook thoroughly, you must turn in summary notes on the readings on each Monday, no later than 11:59PM. (A form will be provided on the course web page.) If you like to take notes on paper, then just attach a photo or two of your notebook pages. If you type them out, then attach a PDF instead.
Your notes can be organized in whatever way is appropriate to that chapter and is useful for you. Good things to include may be an outline of the chapter, definition of key terms, a sketch of the systems or data structures being discussed, that sort of thing.

Along with your notes, you should submit one thoughtful question you would like to discuss that week. I will try to answer a few highlighted questions each week, and steer the lecture to address them.

Grading on notes will be very simple: either one, one-half, or zero points. There will be twelve opportunities to earn a total of ten points, so you may miss up to two without penalty.

Attendance

To succeed in this class, you should attend and actively participate in all the scheduled lectures, however, attendance is not taken.
Grading

The course grade will be based on six programming projects, a midterm, and a final exam. For each assignment, a numeric grade will be assigned. Grades will be made available in Sakai. Projects and homeworks are 60% of the course grade, chapter notes are 10%, and the midtem and final exam are together 30%. At the end of the semester, number grades will be converted to letter grades: 90/80/70 are the usual cutoffs for A/B/C grades, respectively. The instructor will exercise discretion on borderline grades, or to account for a trend of increasing/decreasing grades throughout the semester.
Late assignments receive no credit. You are free to turn in programming assignments multiple times before the deadline expires. It would be a good habit to turn in an incomplete but working assignment on a daily basis. Thus, there is no excuse for failing to turn in an assignment: everyone should turn in something long before the deadline.

Exceptions will only be made for serious circumstances beyond your control (e.g. major illness) or participation in an official University activity. In either case, please confer with the instructor as soon as you are able.

If you believe an error has been made in grading an item, please bring it to the attention of the TA who graded it within seven days of receiving it. (The TA who graded it knows the details best, and so can give you the best explanation.) Factual and clerical errors will of course be cheerfully corrected. If you are unsatisfied with the TA's explanation, you may appeal to the instructor. After seven days, graded items are final and will not be revisited.

Classroom Recording Notification

This course will be recorded using Panopto and made available on Sakai. This system allows us to automatically record and distribute lectures in a secure environment. You are welcome to watch the lecture videos if you are out sick, travelling for an interview, or just need a review. (But videos aren't a substitute for regular attendance.) Because we will be recording in the classroom, your questions and comments may be recorded. Recordings typically only capture the front of the classroom, but if you have any concerns about your voice or image being recorded please speak to me to discuss your concerns. These recordings are jointly copyrighted by the University of Notre Dame and your instructor. Posting them to other websites or services without express, written permission may result in disciplinary action and possible civil prosecution.
Academic Code of Honor

As a student at Notre Dame, you are bound by the Academic Code of Honor (http://honorcode.nd.edu), which states:
As a member of the Notre Dame community, I acknowledge that it is my responsibility to learn and abide by principles of intellectual honesty and academic integrity, and therefore I will not participate in or tolerate academic dishonesty.
The purpose of the homeworks and assignments in this course is for each student to gain the discipline and skills in design, programming, and analysis, so that they will be able to work independently in a professional setting.
To that end, all exams, homeworks, and programming assignments are to be completed individually. Each student must write their own code from scratch with their own hands based on their own understanding of the course material.

You may consult with other students and outside resources in order to better understand concepts and techniques, or to debug localized problems. You may not copy code from another student or resource, excepting any starter code provided by the instructor.

Some Campus Resources

If you require an accommodation for a disability, please first contact the Sara Bea Center (sarabeadisabilityservices.nd.edu) for a consultation, and we will be happy to work together on a solution. If you encounter a difficult life situation and don't know what to do, the University Counseling Center (ucc.nd.edu) or the Care and Wellness Consultants (care.nd.edu) can help and also connect you with other campus resources.
