/******************************************************************************
  Title          : subway_system.h
  Author         : Keisuke Suzuki
  Created on     : April 18, 2018
  Description    : Header file for the SubwaySystem class derives the class
                   _SubwaySystem
  Purpose        : To give an interface for SubwaySystem class

******************************************************************************/

#ifndef SW2_SUBWAY_SYSTEM_H
#define SW2_SUBWAY_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>
#include <cfloat>
#include"_subway_system.h"
#include "subway_route.h"
#include "subway_portal.h"
#include "subway_station.h"
#include "_hash_item.h"
#include "hash_table.h"

using namespace std;

class SubwaySystem: public _SubwaySystem{
    
    public:
    /** default constructor it initialize all the members in the class
     *  @pram: non
     *  @precondition none
     *  @postcondition none
     */
    SubwaySystem();
    
    /** SubwaySystem() is a copy constructor
     * @param: other
     * @precondition none
     * @postcondition none
     */
    SubwaySystem(const SubwaySystem &other);
    
    /** SubwaySystem& operator=() is an assignment operator
     * @param other
     * @return pointer of this pointer
     */
    SubwaySystem &operator=(const SubwaySystem &other);
    
    /**~SubwaySystem()
     * @param other
     * @precondition none
     * @postcondition none
     */
    ~SubwaySystem();
    
    /** add_portal()  adds the given portal to the array of portals
     *  It also creates a hash table entry for this portal that points to
     *  its location in the array.
     *  @param  SubwayPortal [in] portal: an initialized portal
     *  @return int  1 if successful, 0 if portal is not added.
     */
    int add_portal(SubwayPortal portal);
    
    /** list_all_stations() lists all subway station names on the given stream
     *  @param [inout] ostream out is an open output stream
     */
    void list_all_stations(ostream &out);
    
    /** list_all_portals() lists all portals to a given station on given stream
     *  @param [inout] ostream is an open output stream
     *  @param [in]  string station_name is the exact name of a station,
     *          which must be the name of the set of portal names. These can
     *          be obtained from the output of list_all_stations().
     */
    void list_all_portals(ostream &out,string station_name);
    
    /** list_stations_of_route() lists all station names on the given route on
     *          the given output stream
     *  @param [inout] ostream is an open output stream
     *  @param [in]  route_id route is the name of the subway route whose
     *          stations are to be printed onto the stream
     */
    void list_stations_of_route(ostream &out,route_id route);
    
    
    /** form_stations()
     *  Note: form_stations should be called once after the array of portals
     *  has been created. It determines which portals are connected to each
     *  other and forms disjoint sets of connected stations and portals.
     *  After all sets are formed, it stores the names of the stations that
     *  name these sets (e.g., if parent trees, the ones at the root)
     *  in a hash table for station names for fast access.
     *  Finally, it sets an internal flag to indicate that the sets have been
     *  computed.
     *  @return int : number of sets created
     */
    int form_stations();
    
    /** get_portal() searches for a portal whose name equals name_to_find
     *  @param string [in]  name_to_find is the portal name to look up
     *  @param SubwayPortal & [out] is filled with the data from the Portal
     *         if it is found, or is an empty Portal whose name is ""
     *  @return bool true if anf only if the portal is found
     */
    bool get_portal(string name_to_find,SubwayPortal &portal);
    
    
    /** nearest_portal() returns a string representation of the portal that
     *  is nearest to the given point
     *  @param  double [in]  latitude of point
     *  @param  double [in]  longitude of point
     *  @return string       portal's name (as defined in subway_portal.h)
     */
    string nearest_portal(double latitude,double longitude);
    
    /** nearest_routes() returns a string representation of the routes that
     *  are nearest to the given point
     *  @param  double [in]  latitude of point
     *  @param  double [in]  longitude of point
     *  @return string       representation of set of routes
     */
    string nearest_routes(double latitude,double longitude);
    
    /** union_set() it sets parent node of root2 to root1
     * @param root1
     * @param root2
     * @precondition: root1 and root2 is the root of the parent tree
     * @postcondition: root2 is child of root1
     */
    void union_set(size_t root1,size_t root2);
    
    /** find() it sets parent node of root2 to root1
     * @param int: i
     * @precondition: all stations are united to disjoint set
     * @postcondition: all stations
     */
    int find(int i);
    
    private:
    //pointer of vector of parent tree that stores portals
    vector<SubwayStation>* stations;
    
    //hash_table with embedded portal name of the station as key and the
    // index where it's stored as data
    HashTable portal_table;
    
    //hash_table with unique station name of the station as key and the
    // index where it's stored as data
    HashTable station_table;
    
    //pointer of a vector of SubwayRoute class
    vector<SubwayRoute>* routes;

};




#endif //SW2_SUBWAY_SYSTEM_H
