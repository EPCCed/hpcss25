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

We will be using an Image Sharpening example, a program that we will come back to in the HPC sessions on
Thursday and Friday when we will be experimenting with a range of parallelisation options.

For now this exercise illustrates a number of points:

 * an algorithm that does a significant amount of computation;
 * how to run a Python program on the Cirrus login node;
 * how to compile and run a C program on the Cirrus login node;
 * a comparison of the relative performance of C and (naively written) Python;
 * an opportunity to see a real C program (warts and all!).

You can find the image sharpening example at https://github.com/EPCCed/hpcss24-sharpen

I will explain this program and how it works on Thursday but for now we'll just be using the Python and C serial versions (in the P-SER and CSER directories) as examples of program that do lots of computation.

If you want to learn a bit more about the algorithm here is a [sneak preview of Thursday's talk](docs/.). In essence it loops over all the pixels in an image
and applies a large filter to each pixel that uses the values of the pixels in its near vicinity (by default a 17x17 square).

On Cirrus you will need to load a module to get a suitable version of Python: module load python/3.9.13

To view the input and output images (fuzzy.pgm and sharpened.pgm), use `module load ImageMagick` then display `image.pgm`. If you cannot get graphics
to work on your machine then you can copy the images back to your desktop, but you will have to convert then to a non-PGM format first. For example, on Cirrus you can
issue `convert sharpened.pgm sharpened.png`.

Things you might like to investigate:

    How fast is the code on your laptop compared to the Cirrus login nodes?

    If you want the program to run faster you can change the size of the smoothing filter - try reducing the value of d in sharpenalg.py from its default value d=8. How does the runtime vary with d? Can you understand this behaviour by looking at the code?

    The program is deliberately written very simply and the performance can easily be improved. For example, the values of the (very time-consuming) function filter() could be pre-calculate and stored in an array. If you do alter the code make sure that the output is still correct, e.g. by comparing the output image sharpened.pgm.
