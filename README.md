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


  * The algorithm may take a large number of iteratios to converge,
    especially for large problem sizes. If it does not reach
    convergence then the output pictures will look weird. However, it
    is **still OK in terms of performance** as each iteration takes
    the same time.

### Running on the GPU

I have added a GPU example to the sharpen repo - do a "git pull" to
make sure you have the up-to-date versions.

There is an exercise sheet at [https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpengpu.pdf](https://github.com/EPCCed/hpcss24-sharpen/blob/main/doc/sharpengpu.pdf).

As before, **please ignore** anything this sheet says about downloading code from elsewhere - use the HPCSS24 repos!