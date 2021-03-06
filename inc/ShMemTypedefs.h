/**
 * @brief 
 * @file ShMemTypedefs.h
 *
 * This file is created at Almende B.V. It is open-source software and part of the Common
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from
 * thread pools and TCP/IP components to control architectures and learning algorithms.
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software being used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * Copyright © 2012 Bart van Vliet <bart@almende.com>
 *
 * @author        Bart van Vliet
 * @date          Oct 3, 2012
 * @project       
 * @company       Distributed Organisms B.V.
 * @case          Swarm robots
 */

#ifndef SHMEMTYPEDEFS_H_
#define SHMEMTYPEDEFS_H_

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/set.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

#include "UAVStructs.h"
#include "Fitness.h"
#include "Fire.h"

typedef boost::interprocess::managed_shared_memory MapShMemType;
typedef boost::interprocess::managed_shared_memory::segment_manager SegmentManagerType;
typedef boost::interprocess::interprocess_mutex MapMutexType;
typedef boost::interprocess::allocator<void, SegmentManagerType> MapVoidAllocatorType;


///// Uav Map /////
typedef int										MapUavKeyType;
typedef MapUavStruct							MapUavMappedType;
typedef std::pair<const MapUavKeyType, MapUavMappedType>	MapUavValueType;

typedef boost::interprocess::allocator<MapUavValueType, SegmentManagerType> MapUavAllocatorType;
typedef boost::interprocess::map<MapUavKeyType, MapUavMappedType, std::less<MapUavKeyType>, MapUavAllocatorType> MapUavType;
typedef MapUavType::iterator MapUavIterType;


///// Gaussian 2D vector /////
typedef boost::interprocess::allocator<FitnessGaussian2D, SegmentManagerType>  FitnessAllocatorType;
typedef boost::interprocess::vector<FitnessGaussian2D, FitnessAllocatorType> FitnessVecType;
typedef FitnessVecType::iterator FitnessVecIterType;


///// Gaussian 3D vector /////
typedef boost::interprocess::allocator<FitnessGaussian3D, SegmentManagerType>  Fitness3DAllocatorType;
typedef boost::interprocess::vector<FitnessGaussian3D, Fitness3DAllocatorType> Fitness3DVecType;
typedef Fitness3DVecType::iterator Fitness3DVecIterType;
typedef Fitness3DVecType::reverse_iterator Fitness3DVecRiterType;


///// Wall vector /////
typedef boost::interprocess::allocator<FitnessQuadraticWall, SegmentManagerType>  FitnessWallAllocatorType;
typedef boost::interprocess::vector<FitnessQuadraticWall, FitnessWallAllocatorType> FitnessWallVecType;
typedef FitnessWallVecType::iterator FitnessWallVecIterType;


///// Coverage map /////
typedef int FitnessMapKeyType;
typedef FitnessGaussian2D FitnessMappedYType;

typedef std::pair<const FitnessMapKeyType, FitnessMappedYType> FitnessMapValueYType;
typedef boost::interprocess::allocator<FitnessMapValueYType, SegmentManagerType> FitnessMapAllocatorYType;
typedef boost::interprocess::map<FitnessMapKeyType, FitnessMappedYType, std::less<FitnessMapKeyType>, FitnessMapAllocatorYType> FitnessMapYType;
typedef FitnessMapYType::iterator FitnessMapIterYType;

typedef FitnessMapYType FitnessMappedXType;
typedef std::pair<const FitnessMapKeyType, FitnessMappedXType> FitnessMapValueXType;
typedef boost::interprocess::allocator<FitnessMapValueXType, SegmentManagerType> FitnessMapAllocatorXType;
typedef boost::interprocess::map<FitnessMapKeyType, FitnessMappedXType, std::less<FitnessMapKeyType>, FitnessMapAllocatorXType> FitnessMapXType;
typedef FitnessMapXType::iterator FitnessMapIterXType;


///// Fire Map /////
//typedef int													MapFireKeyType;
//typedef MapFireStruct										MapFireMappedType;
//typedef std::pair<const MapFireKeyType, MapFireMappedType>	MapFireValueType;
//
//typedef boost::interprocess::allocator<MapFireValueType, SegmentManagerType> MapFireAllocatorType;
//typedef boost::interprocess::map<MapFireKeyType, MapFireMappedType, std::less<MapFireKeyType>, MapFireAllocatorType> MapFireType;
//typedef MapUavType::iterator MapFireIterType;

typedef int FireMapKeyType;
typedef MapFireStruct FireMappedYType;

typedef std::pair<const FireMapKeyType, FireMappedYType> FireMapValueYType;
typedef boost::interprocess::allocator<FireMapValueYType, SegmentManagerType> FireMapAllocatorYType;
typedef boost::interprocess::map<FireMapKeyType, FireMappedYType, std::less<FireMapKeyType>, FireMapAllocatorYType> FireMapYType;
typedef FireMapYType::iterator FireMapIterYType;

typedef FireMapYType FireMappedXType;
typedef std::pair<const FireMapKeyType, FireMappedXType> FireMapValueXType;
typedef boost::interprocess::allocator<FireMapValueXType, SegmentManagerType> FireMapAllocatorXType;
typedef boost::interprocess::map<FireMapKeyType, FireMappedXType, std::less<FireMapKeyType>, FireMapAllocatorXType> FireMapXType;
typedef FireMapXType::iterator FireMapIterXType;

#endif /* SHMEMTYPEDEFS_H_ */
