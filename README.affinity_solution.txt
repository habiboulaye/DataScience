//============================================================================
// Name        : Affinity 
// Description : Compatibility test, Audience targeting, Customers profiling
// Version     : 1.0
// Language     : C++
// Copyright   : Co. 2011-2013
// Author      : Habib
// Email	   : habiboulaye@gmail.com
//============================================================================
// 1. Overview :
// The Test solutions are coded in C++. All solutions are proposed in OO 
// Designed. Each test is 
//
// - SOLUTION 1 : 
// We propose a more generalizable solution that can easly be extended to topn
// results by settling _ntop parameter. It is possible to propose a more faster 
// solution if only top2 results are required without no possible extension
//
// - SOLUTION 2 :
// No comment
// 
// - SOLUTION 3 :
// We consider a parameter _nmax_playlist that corresponds to the maximal number 
// of songs in the playlist by a day. This will useful for very large data. Hence, 
// the objective of collegues satisfaction is tracked for a period cover one day.
// 
// - SOLUTION 4 :
// The parameter _naffinity allows algorithm flexibility. It collegue compatibility
// comes to be more constraint, we have to increase this parameter value.
// Under study: How symetric relation of compatibility could improve time complexity?
//
//============================================================================
// 2. Installation
// These solutions are proposed with the following configuration 
// - OS: Linux plateform
// - Compiler: gcc 
// - Library: stl
//
// 2.1 Compilation
>> cd /Path/To/Dir/Affinity
>> make

// 2.2 Test example
>> cat Affinity.sample.data | Solution4
