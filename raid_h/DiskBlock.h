#ifndef RAID_H_DISKBLOCK_H_
#define RAID_H_DISKBLOCK_H_
#include <vector>
#include <string>
#include <iostream>

namespace raid {

struct Video_Container {
	std::string video_binary_data;
	std::string video_id;
	int chunk_order;
	int mat_number;
	Video_Container( std::string binary, std::string id, int order, int mat ) : video_binary_data( binary ),video_id( id ), chunk_order( order ), mat_number( mat ) { }

	void print() {
		std::cout << video_id << " O: " << chunk_order << std::endl;
	}

	bool operator < ( const Video_Container& vc ) const {
		return chunk_order < vc.chunk_order;
	}

	bool operator > ( const Video_Container& vc ) const {
		return chunk_order > vc.chunk_order;
	}
};

typedef unsigned int u_int;
typedef std::vector<Video_Container> Video_Collection;
typedef std::vector<Video_Container*> Container_Ptr;

class Disk_Block {
public:
	Disk_Block( u_int mem_size );
	void set_id( std::string id );
	void insert_video_data( std::string binary, std::string vid_id, int chunk_order, int mat );
	Video_Collection group_by_mat_number( std::string vid_id, int mat );
	virtual ~Disk_Block();
private:
	u_int m_capacity;
	std::string block_id;
	Video_Collection m_collection;
};

} /* namespace raid */

#endif /* RAID_H_DISKBLOCK_H_ */
