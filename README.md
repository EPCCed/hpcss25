# EPCC HPC Summer School 2025

This page contains key dates and information for the EPCC HPC Summer
School 2025 from Saturday June 14th to Saturday June 28th.

For the HPC Summer School we're using material from a range of
existing courses so this is also a central page to help collect them all
together.

## Schedule

### Arrival

There will be a "get-together" meal (food and soft drinks provided) at
**7pm on Saturday 14th** at [Pizza Posto](https://pizzaposto.co.uk/):
16 Nicolson St, Edinburgh, EH8 9DH. This is less than 10 minutes' walk
from the flats in Darroch Court.

### Lectures

The standard day will run from 09.30 to 17:00 with an hour for lunch
around 12:30 and coffee breaks mid-morning and mid-afternoon.

However, for the first day **Monday 16th** could you please arrive at
the Bayes Building, 47 Potterrow, Edinburgh EH8 9BT, **at 09:00** to
give us more time for introductions, admin tasks etc.

Lectures will take place in Bayes or Room 2.14 in the **Lister Learning
and Teaching Centre**, 5 Roxburgh Pl, Edinburgh EH8 9SU (this is about 5
minutes from Darroch Court).

Here is the schedule: in practical sessions students will work on
their own on exercises based on the lecture material, with an EPCC
staff member on hand to help.

| Day | Morning (normally 9:30)  || Afternoon (normally 14:00) ||
| --- | ---|--  | --- |--|
| |  | |
| Mon 16 | Bayes (**arrive 09:00**) | Introductions / bash / git | Bayes | bash / git |
| Tue 17 | Bayes | Python / numpy |Bayes |  [Introduction to Compilers](./introduction-to-c/slides/compiler-essentials-slides.pdf) / [Introduction to C](./introduction-to-c/slides/c-essentials-slides.pdf) |
| Wed 18 | Lister | [Introduction to C](./introduction-to-c/slides/c-essentials-slides.pdf) | Bayes | Practical |
| Thu 19 | Bayes | Introduction to HPC (i) | Bayes | Practical |
| Fri 20| Bayes | Introduction to HPC (ii) | Bayes | Practical |
| | | | | |
| Mon 23 | Bayes | OpenMP for CPUs (i) | Bayes |  OpenMP for CPUs (ii) |
| Tue 24 | Lister | OpenMP for CPUs (iii) | Bayes |  Practical |
| Wed 25 | Lister | OpenMP for GPUs  | Bayes |  ACF visit |
| Thu 26 | Lister | Introduction to MPI | Bayes |  Practical |
| Fri 27 | Bayes | HPC Guest Lectures | Bayes | Practical |

### Wednesday PM

This afternoon practical session is a chance for you to either catch up with the material from the
first few days (if it was new to you) or to work on a more substantial problem.

We will be using an **Image Sharpening example**, a program that we will come back to in the HPC sessions on
Thursday and Friday when we will be experimenting with a range of parallelisation options.

For now this exercise illustrates a number of points:

 * an algorithm that does a significant amount of computation;
 * how to run a Python program on the Cirrus login node;
 * how to compile and run a C program on the Cirrus login node;
 * a comparison of the relative performance of C and (naively written) Python;
 * an opportunity to see a real C program (warts and all!).

You can find the image sharpening example at https://github.com/EPCCed/hpcss24-sharpen

I will explain this program and how it works on Thursday but for now we'll just be using the Python and C serial versions (in the P-SER and CSER directories) as examples of programs that do lots of computation.

If you want to learn a bit more about the algorithm here is a [sneak preview of Thursday's talk](IntroHPC/L02_Sharpen.pdf). In essence it loops over all the pixels in an image
and applies a large filter to each pixel that uses the values of the pixels in its near vicinity (by default a 17x17 square).

On Cirrus you will need to load a module to get a suitable version of Python: `module load python`

To view the input and output images (fuzzy.pgm and sharpened.pgm), use `module load ImageMagick` then `display fuzzy.pgm`. If you cannot get graphics
to work on your machine then you can copy the images back to your desktop, but you will have to convert then to a non-PGM format first. For example, on Cirrus you can
issue `convert fuzzy.pgm fuzzy.png`.
#### Timing

The code prints out times: the calculation time and the overall run time. The calculation time just measures how long it took to apply the filter to the image **excluding** the IO overheads of reading in the fuzzy image and writing out the sharpened one; the overall run time is the total time from start to finish. To find out how long was spent in IO just subtract the two.

#### Python example

Things you might like to investigate:

*    How fast is the code on your laptop compared to the Cirrus login nodes?

*    If you want the program to run faster you can change the size of the smoothing filter - try reducing the value of `d` in `sharpenalg.py` from its default value d=8. How does the runtime vary with d? Can you understand this behaviour by looking at the code?

*    The program is deliberately written very simply and the performance can easily be improved. For example, the values of the (very time-consuming) function `filter()` could be pre-calculated and stored in an array. If you alter the code make sure that the output is still correct, e.g. by comparing the output image `sharpened.pgm` before and after your changes: they should be **identical**.

  #### C example

The C example is described in [https://github.com/EPCCed/hpcss24-sharpen/doc/sharpen-cirrus1.pdf](https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpen-cirrus1.pdf).

This sheet covers a lot of topics and assumes you have not used Cirrus before. The material in sections 3.6 to 3.8 is most relevant here: you can
skip most of the early sections. The instructions talk about downloading a tar file but you do not need to do this as you already have the source code from github. I have also not included any Fortran versions for simplicity.

Things to look at include:

 *   Do you understand the code? The way 2D arrays are allocated using `malloc` is a little complicated - if you really want to know what is going on here then ask a demonstrator!
 *   How much faster is the compiled C version compared to the Python code?
 *   Does adding compiler optimisation (e.g. -O3) change the performance?
 *   Does using the GNU compiler gcc, as opposed to Intel's icc, change performance?


### Thursday PM

This is an opportunity for you to investigate parallel scaling of the
image sharpening example as described in sections 3.9 onward of:
[https://github.com/EPCCed/hpcss24-sharpen/doc/sharpen-cirrus1.pdf](https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpen-cirrus1.pdf).
The are also additional exercises in
[https://github.com/EPCCed/hpcss24-sharpen/doc/sharpen-cirrus2.pdf](https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpen-cirrus2.pdf).

Remember that you should change the line `#SBATCH --account=tc063` to
`#SBATCH --account=tc069`

#### Using the reservation

We have 8 nodes reserved for the Summer School. To use these, specify:
````
#SBATCH --qos=reservation
#SBATCH --reservation=tc069_1525575
````

### Exercises

The default exercises are around looking at the scaling of the pure
MPI version and seeing if it follows Amdahl's law. You should:

  * plot graphs of speedup and parallel efficiency
  * see what value of alpha gives a good fit
  * check if this agrees with what you would estimate from the IO time

If you want to look at Gustafson's law - larger problems scale better
- then increase the filter size by changing `d`, e.g. you could try
`d=10` or `d=14`.

The second sheet also mentions OpenMP which is an example of
loop-based parallelism. You can run these if you want but all the
details will be explained next week.

### Friday

The main aim of today is to run parallel scaling of the CFD example
and investigate Amdahl's law and Gustafson's law.

You should plot speedup curves for a number of problem sizes to verify
that larger problems scale better. It is often convenient to double
the process count, e.g run in 1, 2, 4, 8, 16, 32, 64, 128 and 256
processes (or some subset thereof). For large process counts you will
probably have to use large problem sizes, i.e. a large value for the
scale factor.

The exercise sheet is at 
[https://github.com/EPCCed/hpcss24-cfd/blob/main/doc/cfd-hpcss24.pdf](https://github.com/EPCCed/hpcss24-cfd/blob/main/doc/cfd-hpcss24.pdf).
  * The exercise sheets may say "download the code from here" - you
    should **ignore this** and use the codes in the HPCSS24 git repos.

  * When setting up the jobs you specify `nodes`, `ntasks` and
    `tasks-per-node` (you should leave `cpus-per-task=1`). The most
    important value is `ntasks` - this is how many MPI processes you
    want to run on. If this is larger than 36 then you will need to
    request more than one node. You can actually remove
    `tasks-per-node` if you want and SLURM will try and figure out how
    to distribute the tasks to the nodes, but for more control you can
    set it yourself.

  * For example, if you wanted to run on 128 MPI processes then set
    `ntasks=128`. This will need at least 4 nodes so set `nodes=4`. If
    you want the MPI processes to be distributed evenly to the nodes
    then set `tasks-per-node=32`.

  * Jobs already should be set to run in the reservation which has 8 nodes.

  * Remember that the runtime should be something like one second or
    more to be reliable. If you us small problem sizes or large
    numbers of processes then it may run too quickly - you should run
    using more iterations.

  * You can vary the amount of computation the code does by setting a
    finite value of the Reynold's number - see the exercise sheet for
    details (this also gives much nicer pictures!).


  * The algorithm may take a large number of iterations to converge,
    especially for large problem sizes. If it does not reach
    convergence then the output pictures will look weird. However, it
    is **still OK in terms of performance** as each iteration takes
    the same time.

### Running on the GPU

I have added a GPU example to the sharpen repo - do a "git pull" to
make sure you have the up-to-date versions.

There is an exercise sheet at [https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpengpu.pdf](https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpengpu.pdf).

As before, **please ignore** anything this sheet says about downloading code from elsewhere - use the HPCSS24 repos!

### Tuesday PM

  You are welcome to continue with Mark's OpenMP
  exercises. However, if you want to tackle something different see
  below:

#### Sharpen example

The way that I have parallelised `doharpen()` in OpenMP is a bit weird - it is done by hand and does not use `parallel for`.

*  Rewrite the code so it uses `parallel for` over the first loop
  rather than switching based on the value of `pixcount`. Is the
  performance similar to the original version? What loop schedule
  should you use - does it make a difference to performance?

 *   [Here is a version of `dosharpen`](OpenMP/dosharpen.c) written
  deliberately to have load imbalance within the main loop (the width
  of the filter is varied across the image from `2` to `d`). As
  above, rewrite the code to use `parallel for`. Does the loop
  schedule affect performance for the load-imbalanced sharpening
  algorithm?  What is the best schedule - `static`, `dynamic`. ... ?

#### CFD example

The CFD exercise sheet only covers the serial and MPI versions of the
  cfd example. Here are some things you could consider with the serial
  Python and parallel OpenMP versions. When compiling code I would
  recommend using the `-O3` optimisation level.


Visualising the Python output requires you to run an additional
    program: ` python ./plot_flow.py velocity.dat colourmap.dat
    output.png`. You can then view the PNG file with `display`.

* How long does the Python code take compared to the serial C code
    (consider a small example for a reasonable runtime)?
* Is the performance different on the login vs compute nodes (you will
    need to write an appropriate Slurm script). What about the serial
    C code?
* There is a version that uses numpy arrays and array syntax rather
    than lists and explicit loops - see `cfd_numpy` and
    `jacobi_numpy`. How much faster is this than the basic Python
    code? Do you understand why? Again, is there a performance difference between login and compute nodes?

* Try running the OpenMP code - how does its performance scale with
  varying values of `OMP_NUM_THREADS`. For large values you must run
  on the compute nodes - again, you will need to write a Slurm
 script to run on a single node: specify `partition=standard` and `qos=short`.   How does this compare to MPI? Do you seen any unusual
  effects when the thread count exceeds 18 - can you explain this?

* How does the OpenMP performance scaling compare between the default
  parameters and running with a finite value of the Reynolds number,
  e.g. 2.0? Can you see what the problem is? Can you fix it by adding
  appropriate OpenMP directives?

### Friday AM

**This session takes place in the main ground floor Bayes lecture room G.03**

The session will comprise guest lectures from a range of HPC
experts. Catering will be provided so please arrive well before the
first talk to ensure you get a free breakfast!

| Time | Event |
| --- | ---  |
|09:30 - 10:00| Tea, coffee and cakes (provided) |
|10:00 - 11:00| Prof Mark Parsons, Director of EPCC: "The Next UK National Supercomputing Service: Plans for an Exascale Machine in Edinburgh" |
|11:00 - 11:30| Tea and coffee (provided) |
|11:30 - 12:00| Kirsty Pringle (EPCC) "The Role of Research Software Engineers in Public Engagement" |
|12:00 - 12:45| Andrew Turner (EPCC) "Understanding and Reducing Carbon Emissions from HPC Systems" |

