# CRSS Speaker Diarization Toolkit (CRSS-SpkrDiar)
## About
CRSS-SpkDiar is a C++ based speaker diarization toolkit, built on top of famous open source speech recognition platform of [Kaldi](http://kaldi.sourceforge.net/). The main objective of this toolkit is as follow:

  - Simple integration with Kaldi ASR, 
  - Simple intergration of i-vector training and extraction within Kaldi for Diarization
  - Simple intergration of DNN within Kaldi for Diarization 
  - Perform speaker diarization unsupervised/supervised/semi-supervised fasion
  - Benchmark on open database (AMI meeting corpus, and more)

Authors: [Chengzhu Yu](https://sites.google.com/site/chengzhuyu0/home) and [Navid Shokouhi](https://scholar.google.com/citations?user=DHxzPt8AAAAJ&hl=en).

_We plan to officially realease CRSS-SpkrDiar toolkit around January, 2017. 
As the current version is not completed, with several missing components,
we do not recommend you to try it. As long as it is ready, we will include installation guidance and the recipe to 
reproduce our results._

## Current Stage of Development
##### _Completed:_
 - Bottom-Up Clustering Using BIC, Symmetric KL divergence
 - Bottom-Up Clustering Using i-vector cosine distance score (CDS).
 - ILP Clustering with i-vector CDS as distance.

##### _To Be Completed:_
 - Test and incorporate PLDA, Conditional Bayes, Mahalanobis distance for clustering    
 - Sementation
 - Supervised/Semi-supervised Diarization
 - Generate flexible interface with Kaldi ASR

## Dependencies
  - Kaldi
  - GLPK (if only you want to try ILP)
  
## Benchmark Pefformance
We evaluate our performance on [AMI meeting corpus](http://groups.inf.ed.ac.uk/ami/download/) and comparing the numbers with those reported in [Pycasp](http://multimedia.icsi.berkeley.edu/scalable-big-data-analysis/pycasp/) from ICSI. Note: To evaluate only the clustering module, the numbers on CRSS-SpkDiar is on top of orace segmentation. We're currently working on to include segmentation.

| Session       |      Pycasp   |   CRSS-SpkDiar (run2.sh) |
| ------------- | ------------- | -------------   | 
IS1000a.Mix-Headset | 25.38 | 12.07|
IS1001a.Mix-Headset | 32.34 | 43.64|
IS1001b.Mix-Headset | 10.57 | 12.16 |
IS1001c.Mix-Headset | 28.40 | 6.17|
IS1003b.Mix-Headset | 34.30 | 10.56|
IS1003d.Mix-Headset | 50.75 | 24.67|
IS1006b.Mix-Headset | 16.57 | 7.34 |
IS1006d.Mix-Headset | 53.05 | 21.56 |
IS1008a.Mix-Headset | 1.65  | 4.07 |
IS1008b.Mix-Headset | 8.58  | 3.60  |
IS1008c.Mix-Headset | 9.30  | 6.36 | 
IS1008d.Mix-Headset | 26.27 | 5.99 | 
Average             | 24.76% |**13.19%** | 
