#ifndef KALDI_SRC_DIAR_CLUSTERING_H_
#define KALDI_SRC_DIAR_CLUSTERING_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "util/common-utils.h"
#include "matrix/matrix-lib.h"
#include "diar-utils.h"


namespace kaldi{

#define GLR_DISTANCE 0
#define KL2_DISTANCE 1

class Cluster {
public:
	Cluster(Segment one_segment);
	void AddSegment(Segment new_segment);
	std::vector<Segment> AllSegments() const;
	std::string Label() const;
	int32 NumFrames() const;
	int32 NumSegments() const;
	Segment KthSegment(int32 k) const;
	BaseFloat LogDet(const Matrix<BaseFloat> &feats) const;
	static Vector<BaseFloat> ComputeMean(const Matrix<BaseFloat>& feats, const Cluster* clust); 
	static Vector<BaseFloat> ComputeCovDiag(const Matrix<BaseFloat>& feats, const Cluster* clust);
	static Vector<BaseFloat> ComputeSum(const Matrix<BaseFloat>& feats, const Cluster* clust); 
	static Vector<BaseFloat> ComputeVarSum(const Matrix<BaseFloat>& feats, const Cluster* clust);
	Cluster* prev;
	Cluster* next;

	static int id_generator;
	static string prefix;

private:
	std::vector<Segment> list_;
	std::string label_;
	int32 frames_;
};


class ClusterCollection {
public:
	ClusterCollection();
	string UttID();
	void InitFromNonLabeledSegments(SegmentCollection non_clustered_segmemts);
	//InitFromLabeledSegments(SegmentCollection);
	void BottomUpClustering(const Matrix<BaseFloat> &feats, int32 target_cluster_num, const int32& dist_type = 0);
	void FindMinDistClusters(const Matrix<BaseFloat> &feats, std::vector<std::vector<BaseFloat> >& dist_matrix, 
		std::vector<bool>& to_be_updated, std::unordered_map<Cluster*, int32>& cluster_idx_map, std::vector<Cluster*> &min_dist_clusters);
	static void MergeClusters(Cluster* clust1, Cluster* clust2);
	BaseFloat DistanceOfTwoClustersGLR(const Matrix<BaseFloat> &feats, const Cluster* cluster1, const Cluster* cluster2);
	BaseFloat DistanceOfTwoClustersKL2(const Matrix<BaseFloat> &feats, const Cluster* cluster1, const Cluster* cluster2); 
	void Write(const std::string& segment_dir);
	void WriteToRttm(const std::string& rttm_outputdir);
	Cluster* Head();

private:
	string uttid_;
	int32 num_clusters_;
	Cluster* head_cluster_;
	int32 dist_type_;
};


template <typename T>
std::string ToString(T val)
{
    std::stringstream stream;
    stream << val;
    return stream.str();
}

}

#endif
