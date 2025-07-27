#define SOUFFLE_GENERATOR_VERSION "2.5"
#include "souffle/CompiledSouffle.h"
#include "souffle/SignalHandler.h"
#include "souffle/SouffleInterface.h"
#include "souffle/datastructure/BTree.h"
#include "souffle/io/IOSystem.h"
#include "souffle/utility/MiscUtil.h"
#include <any>
namespace functors {
extern "C" {
souffle::RamDomain binaryOpOnTypes(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain, souffle::RamDomain);
souffle::RamDomain irTypeLub(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain);
souffle::RamSigned stoi(const char *);
souffle::RamDomain unaryOpOnType(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain);
}
} //namespace functors
namespace souffle::t_btree_000_iiii__0_2_3_1__1011__1111 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 4;
using t_tuple = Tuple<RamDomain, 4>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3])) ? -1 : (ramBitCast<RamSigned>(a[3]) > ramBitCast<RamSigned>(b[3])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0))));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))|| ((ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2])) && ((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3]))|| ((ramBitCast<RamSigned>(a[3]) == ramBitCast<RamSigned>(b[3])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))))))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]))&&(ramBitCast<RamSigned>(a[3]) == ramBitCast<RamSigned>(b[3]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_1011(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_1011(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_0::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_000_iiii__0_2_3_1__1011__1111 
namespace souffle::t_btree_000_iiii__0_2_3_1__1011__1111 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_1011(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_1011(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1011(lower,upper,h);
}
range<t_ind_0::iterator> Type::lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1111(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 4 direct b-tree index 0 lex-order [0,2,3,1]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_000_iiii__0_2_3_1__1011__1111 
namespace souffle::t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 4;
using t_tuple = Tuple<RamDomain, 4>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_0 = btree_multiset<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
struct t_comparator_1{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3])) ? -1 : (ramBitCast<RamSigned>(a[3]) > ramBitCast<RamSigned>(b[3])) ? 1 :(0))));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| ((ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))|| ((ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2])) && ((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3]))))))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]))&&(ramBitCast<RamSigned>(a[3]) == ramBitCast<RamSigned>(b[3]));
 }
};
using t_ind_1 = btree_set<t_tuple,t_comparator_1>;
t_ind_1 ind_1;
using iterator = t_ind_1::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
t_ind_1::operation_hints hints_1_lower;
t_ind_1::operation_hints hints_1_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_1010(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_1010(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_1::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_1::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_1::iterator> lowerUpperRange_0100(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_1::iterator> lowerUpperRange_0100(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100 
namespace souffle::t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using t_ind_1 = Type::t_ind_1;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_1.insert(t, h.hints_1_lower)) {
ind_0.insert(t, h.hints_0_lower);
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_1.contains(t, h.hints_1_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_1.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_1.find(t, h.hints_1_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<iterator> Type::lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_1.begin(),ind_1.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_1010(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_1010(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1010(lower,upper,h);
}
range<t_ind_1::iterator> Type::lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_1 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_1.find(lower, h.hints_1_lower);
    auto fin = ind_1.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_1.end(), ind_1.end());
}
return make_range(ind_1.lower_bound(lower, h.hints_1_lower), ind_1.upper_bound(upper, h.hints_1_upper));
}
range<t_ind_1::iterator> Type::lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1111(lower,upper,h);
}
range<t_ind_1::iterator> Type::lowerUpperRange_0100(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_1 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_1.end(), ind_1.end());
}
return make_range(ind_1.lower_bound(lower, h.hints_1_lower), ind_1.upper_bound(upper, h.hints_1_upper));
}
range<t_ind_1::iterator> Type::lowerUpperRange_0100(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_0100(lower,upper,h);
}
bool Type::empty() const {
return ind_1.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_1.getChunks(400);
}
void Type::purge() {
ind_0.clear();
ind_1.clear();
}
iterator Type::begin() const {
return ind_1.begin();
}
iterator Type::end() const {
return ind_1.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 4 direct b-tree index 0 lex-order [0,2]\n";
ind_0.printStats(o);
o << " arity 4 direct b-tree index 1 lex-order [1,0,2,3]\n";
ind_1.printStats(o);
}
} // namespace souffle::t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100 
namespace souffle::t_btree_010_ii__0_1__11__10 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 2;
using t_tuple = Tuple<RamDomain, 2>;
struct updater {
bool update(t_tuple& old_t, const t_tuple& new_t) {
bool changed = false;
if (old_t[1] != new_t[1]) {
    changed = true;
    old_t[1] = new_t[1];
}
return changed;
}
};
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
struct t_comparator_0_aux{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :(0);
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0,std::allocator<t_tuple>,256,typename souffle::detail::default_strategy<t_tuple>::type,t_comparator_0_aux,updater>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_0::iterator> lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_010_ii__0_1__11__10 
namespace souffle::t_btree_010_ii__0_1__11__10 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_11(lower,upper,h);
}
range<t_ind_0::iterator> Type::lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_10(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 2 direct b-tree index 0 lex-order [0,1]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_010_ii__0_1__11__10 
namespace souffle::t_btree_010_ii__0_1__11 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 2;
using t_tuple = Tuple<RamDomain, 2>;
struct updater {
bool update(t_tuple& old_t, const t_tuple& new_t) {
bool changed = false;
if (old_t[1] != new_t[1]) {
    changed = true;
    old_t[1] = new_t[1];
}
return changed;
}
};
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
struct t_comparator_0_aux{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :(0);
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0,std::allocator<t_tuple>,256,typename souffle::detail::default_strategy<t_tuple>::type,t_comparator_0_aux,updater>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_010_ii__0_1__11 
namespace souffle::t_btree_010_ii__0_1__11 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_11(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 2 direct b-tree index 0 lex-order [0,1]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_010_ii__0_1__11 
namespace souffle::t_btree_000_ii__0_1__11__10 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 2;
using t_tuple = Tuple<RamDomain, 2>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_0::iterator> lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_000_ii__0_1__11__10 
namespace souffle::t_btree_000_ii__0_1__11__10 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_11(lower,upper,h);
}
range<t_ind_0::iterator> Type::lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_10(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_10(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 2 direct b-tree index 0 lex-order [0,1]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_000_ii__0_1__11__10 
namespace  souffle {
using namespace souffle;
class Stratum_Positiveness_c6f13be59ac1c916 {
public:
 Stratum_Positiveness_c6f13be59ac1c916(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_010_ii__0_1__11__10::Type& rel_delta_Positiveness_cacdcf6defc09c39,t_btree_010_ii__0_1__11::Type& rel_lub_Positiveness_2446c6015248dfd2,t_btree_000_ii__0_1__11__10::Type& rel_new_Positiveness_74d7aa09d76e3f24,t_btree_010_ii__0_1__11__10::Type& rel_Positiveness_f124c68449d9654b,t_btree_000_iiii__0_2_3_1__1011__1111::Type& rel_edge_04d25f5060e9043b,t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type& rel_vertex_bd7050498d9dc077,std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain, souffle::RamDomain)>& binaryOpOnTypes,std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)>& irTypeLub,std::function<souffle::RamSigned(const char *)>& stoi,std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)>& unaryOpOnType);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_010_ii__0_1__11__10::Type* rel_delta_Positiveness_cacdcf6defc09c39;
t_btree_010_ii__0_1__11::Type* rel_lub_Positiveness_2446c6015248dfd2;
t_btree_000_ii__0_1__11__10::Type* rel_new_Positiveness_74d7aa09d76e3f24;
t_btree_010_ii__0_1__11__10::Type* rel_Positiveness_f124c68449d9654b;
t_btree_000_iiii__0_2_3_1__1011__1111::Type* rel_edge_04d25f5060e9043b;
t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type* rel_vertex_bd7050498d9dc077;
std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain, souffle::RamDomain)>& binaryOpOnTypes;
std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)>& irTypeLub;
std::function<souffle::RamSigned(const char *)>& stoi;
std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)>& unaryOpOnType;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_Positiveness_c6f13be59ac1c916::Stratum_Positiveness_c6f13be59ac1c916(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_010_ii__0_1__11__10::Type& rel_delta_Positiveness_cacdcf6defc09c39,t_btree_010_ii__0_1__11::Type& rel_lub_Positiveness_2446c6015248dfd2,t_btree_000_ii__0_1__11__10::Type& rel_new_Positiveness_74d7aa09d76e3f24,t_btree_010_ii__0_1__11__10::Type& rel_Positiveness_f124c68449d9654b,t_btree_000_iiii__0_2_3_1__1011__1111::Type& rel_edge_04d25f5060e9043b,t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type& rel_vertex_bd7050498d9dc077,std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain, souffle::RamDomain)>& binaryOpOnTypes,std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)>& irTypeLub,std::function<souffle::RamSigned(const char *)>& stoi,std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)>& unaryOpOnType):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_delta_Positiveness_cacdcf6defc09c39(&rel_delta_Positiveness_cacdcf6defc09c39),
rel_lub_Positiveness_2446c6015248dfd2(&rel_lub_Positiveness_2446c6015248dfd2),
rel_new_Positiveness_74d7aa09d76e3f24(&rel_new_Positiveness_74d7aa09d76e3f24),
rel_Positiveness_f124c68449d9654b(&rel_Positiveness_f124c68449d9654b),
rel_edge_04d25f5060e9043b(&rel_edge_04d25f5060e9043b),
rel_vertex_bd7050498d9dc077(&rel_vertex_bd7050498d9dc077),
binaryOpOnTypes(binaryOpOnTypes),
irTypeLub(irTypeLub),
stoi(stoi),
unaryOpOnType(unaryOpOnType){
}

void Stratum_Positiveness_c6f13be59ac1c916::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
signalHandler->setMsg(R"_(Positiveness(id,$Positive()) :- 
   vertex(id,"Literal",_,numAsStr),
   @stoi(numAsStr) > 0.
in file positiveness.dl [15:1-15:90])_");
if(!(rel_vertex_bd7050498d9dc077->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
CREATE_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt,rel_vertex_bd7050498d9dc077->createContext());
auto range = rel_vertex_bd7050498d9dc077->lowerUpperRange_0100(Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt));
for(const auto& env0 : range) {
if( (ramBitCast<RamSigned>(stoi(symTable.decode(env0[3]).c_str())) > ramBitCast<RamSigned>(RamSigned(0)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(RamSigned(5))}};
rel_new_Positiveness_74d7aa09d76e3f24->insert(tuple,READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
}
}
}
();}
signalHandler->setMsg(R"_(Positiveness(id,$Negative()) :- 
   vertex(id,"Literal",_,numAsStr),
   @stoi(numAsStr) < 0.
in file positiveness.dl [16:1-16:90])_");
if(!(rel_vertex_bd7050498d9dc077->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
CREATE_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt,rel_vertex_bd7050498d9dc077->createContext());
auto range = rel_vertex_bd7050498d9dc077->lowerUpperRange_0100(Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt));
for(const auto& env0 : range) {
if( (ramBitCast<RamSigned>(stoi(symTable.decode(env0[3]).c_str())) < ramBitCast<RamSigned>(RamSigned(0)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(RamSigned(2))}};
rel_new_Positiveness_74d7aa09d76e3f24->insert(tuple,READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
}
}
}
();}
signalHandler->setMsg(R"_(Positiveness(id,$Zero()) :- 
   vertex(id,"Literal",_,numAsStr),
   @stoi(numAsStr) = 0.
in file positiveness.dl [17:1-17:86])_");
if(!(rel_vertex_bd7050498d9dc077->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
CREATE_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt,rel_vertex_bd7050498d9dc077->createContext());
auto range = rel_vertex_bd7050498d9dc077->lowerUpperRange_0100(Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt));
for(const auto& env0 : range) {
if( (ramBitCast<RamDomain>(stoi(symTable.decode(env0[3]).c_str())) == ramBitCast<RamDomain>(RamSigned(0)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(RamSigned(6))}};
rel_new_Positiveness_74d7aa09d76e3f24->insert(tuple,READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
}
}
}
();}
[&](){
CREATE_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt,rel_lub_Positiveness_2446c6015248dfd2->createContext());
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
for(const auto& env0 : *rel_new_Positiveness_74d7aa09d76e3f24) {
Tuple<RamDomain,1> env1;
bool shouldRunNested = true;
RamDomain res0 = env0[1];
auto range = rel_new_Positiveness_74d7aa09d76e3f24->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
for(const auto& env1 : range) {
if( (ramBitCast<RamDomain>(env1[1]) != ramBitCast<RamDomain>(env0[1]))) {
shouldRunNested = true;
res0 = irTypeLub(&symTable, &recordTable, res0, env1[1]);
}
}
env1[0] = ramBitCast(res0);
if (shouldRunNested) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env1[0])}};
rel_lub_Positiveness_2446c6015248dfd2->insert(tuple,READ_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt));
}
}
}
();rel_new_Positiveness_74d7aa09d76e3f24->purge();
[&](){
CREATE_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt,rel_lub_Positiveness_2446c6015248dfd2->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
for(const auto& env0 : *rel_lub_Positiveness_2446c6015248dfd2) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_Positiveness_f124c68449d9654b->insert(tuple,READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt));
}
}
();rel_lub_Positiveness_2446c6015248dfd2->purge();
[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
for(const auto& env0 : *rel_Positiveness_f124c68449d9654b) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_delta_Positiveness_cacdcf6defc09c39->insert(tuple,READ_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt));
}
}
();auto loop_counter = RamUnsigned(1);
iter = 0;
for(;;) {
signalHandler->setMsg(R"_(Positiveness(srcId,@unaryOpOnType(type,op)) :- 
   vertex(srcId,"UnaryOperation",_,op),
   edge(srcId,dstId,"Data","operand"),
   vertex(dstId,_,"Data",_),
   Positiveness(dstId,type).
in file positiveness.dl [21:1-25:31])_");
if(!(rel_vertex_bd7050498d9dc077->empty()) && !(rel_edge_04d25f5060e9043b->empty()) && !(rel_delta_Positiveness_cacdcf6defc09c39->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
CREATE_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt,rel_edge_04d25f5060e9043b->createContext());
CREATE_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt,rel_vertex_bd7050498d9dc077->createContext());
auto range = rel_vertex_bd7050498d9dc077->lowerUpperRange_0100(Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(1)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(1)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt));
for(const auto& env0 : range) {
auto range = rel_edge_04d25f5060e9043b->lowerUpperRange_1011(Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(3))}},Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(3))}},READ_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt));
for(const auto& env1 : range) {
if( !rel_vertex_bd7050498d9dc077->lowerUpperRange_1010(Tuple<RamDomain,4>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt)).empty()) {
auto range = rel_delta_Positiveness_cacdcf6defc09c39->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt));
for(const auto& env2 : range) {
if( !(rel_Positiveness_f124c68449d9654b->contains(Tuple<RamDomain,2>{{ramBitCast(env0[0]),ramBitCast(unaryOpOnType(&symTable, &recordTable,env2[1],env0[3]))}},READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(unaryOpOnType(&symTable, &recordTable,env2[1],env0[3]))}};
rel_new_Positiveness_74d7aa09d76e3f24->insert(tuple,READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
}
}
}
}
}
}
();}
signalHandler->setMsg(R"_(Positiveness(srcId,@binaryOpOnTypes(type1,type2,op)) :- 
   vertex(srcId,"BinaryOperation",_,op),
   edge(srcId,dstId1,"Data","left"),
   vertex(dstId1,_,"Data",_),
   Positiveness(dstId,type1),
   edge(srcId,dstId2,"Data","right"),
   vertex(dstId2,_,"Data",_),
   Positiveness(dstId,type2).
in file positiveness.dl [27:1-34:32])_");
if(!(rel_vertex_bd7050498d9dc077->empty()) && !(rel_edge_04d25f5060e9043b->empty()) && !(rel_Positiveness_f124c68449d9654b->empty()) && !(rel_delta_Positiveness_cacdcf6defc09c39->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
CREATE_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt,rel_edge_04d25f5060e9043b->createContext());
CREATE_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt,rel_vertex_bd7050498d9dc077->createContext());
auto range = rel_vertex_bd7050498d9dc077->lowerUpperRange_0100(Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(4)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(4)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt));
for(const auto& env0 : range) {
auto range = rel_edge_04d25f5060e9043b->lowerUpperRange_1011(Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(5))}},Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(5))}},READ_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt));
for(const auto& env1 : range) {
if( !rel_vertex_bd7050498d9dc077->lowerUpperRange_1010(Tuple<RamDomain,4>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt)).empty()) {
for(const auto& env2 : *rel_delta_Positiveness_cacdcf6defc09c39) {
auto range = rel_edge_04d25f5060e9043b->lowerUpperRange_1011(Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(6))}},Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(6))}},READ_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt));
for(const auto& env3 : range) {
if( !rel_vertex_bd7050498d9dc077->lowerUpperRange_1010(Tuple<RamDomain,4>{{ramBitCast(env3[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast(env3[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt)).empty()) {
auto range = rel_Positiveness_f124c68449d9654b->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env2[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env2[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt));
for(const auto& env4 : range) {
if( !(rel_Positiveness_f124c68449d9654b->contains(Tuple<RamDomain,2>{{ramBitCast(env0[0]),ramBitCast(binaryOpOnTypes(&symTable, &recordTable,env2[1],env4[1],env0[3]))}},READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt))) && !(rel_delta_Positiveness_cacdcf6defc09c39->contains(Tuple<RamDomain,2>{{ramBitCast(env2[0]),ramBitCast(env4[1])}},READ_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(binaryOpOnTypes(&symTable, &recordTable,env2[1],env4[1],env0[3]))}};
rel_new_Positiveness_74d7aa09d76e3f24->insert(tuple,READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
}
}
break;
}
}
}
break;
}
}
}
}
();}
signalHandler->setMsg(R"_(Positiveness(srcId,@binaryOpOnTypes(type1,type2,op)) :- 
   vertex(srcId,"BinaryOperation",_,op),
   edge(srcId,dstId1,"Data","left"),
   vertex(dstId1,_,"Data",_),
   Positiveness(dstId,type1),
   edge(srcId,dstId2,"Data","right"),
   vertex(dstId2,_,"Data",_),
   Positiveness(dstId,type2).
in file positiveness.dl [27:1-34:32])_");
if(!(rel_vertex_bd7050498d9dc077->empty()) && !(rel_edge_04d25f5060e9043b->empty()) && !(rel_delta_Positiveness_cacdcf6defc09c39->empty()) && !(rel_Positiveness_f124c68449d9654b->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
CREATE_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt,rel_edge_04d25f5060e9043b->createContext());
CREATE_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt,rel_vertex_bd7050498d9dc077->createContext());
auto range = rel_vertex_bd7050498d9dc077->lowerUpperRange_0100(Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(4)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(4)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt));
for(const auto& env0 : range) {
auto range = rel_edge_04d25f5060e9043b->lowerUpperRange_1011(Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(5))}},Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(5))}},READ_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt));
for(const auto& env1 : range) {
if( !rel_vertex_bd7050498d9dc077->lowerUpperRange_1010(Tuple<RamDomain,4>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast(env1[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt)).empty()) {
for(const auto& env2 : *rel_Positiveness_f124c68449d9654b) {
auto range = rel_edge_04d25f5060e9043b->lowerUpperRange_1011(Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(6))}},Tuple<RamDomain,4>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast(RamSigned(6))}},READ_OP_CONTEXT(rel_edge_04d25f5060e9043b_op_ctxt));
for(const auto& env3 : range) {
if( !rel_vertex_bd7050498d9dc077->lowerUpperRange_1010(Tuple<RamDomain,4>{{ramBitCast(env3[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,4>{{ramBitCast(env3[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(2)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_vertex_bd7050498d9dc077_op_ctxt)).empty()) {
auto range = rel_delta_Positiveness_cacdcf6defc09c39->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env2[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env2[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt));
for(const auto& env4 : range) {
if( !(rel_Positiveness_f124c68449d9654b->contains(Tuple<RamDomain,2>{{ramBitCast(env0[0]),ramBitCast(binaryOpOnTypes(&symTable, &recordTable,env2[1],env4[1],env0[3]))}},READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(binaryOpOnTypes(&symTable, &recordTable,env2[1],env4[1],env0[3]))}};
rel_new_Positiveness_74d7aa09d76e3f24->insert(tuple,READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
}
}
break;
}
}
}
break;
}
}
}
}
();}
if(rel_new_Positiveness_74d7aa09d76e3f24->empty()) break;
rel_delta_Positiveness_cacdcf6defc09c39->purge();
[&](){
CREATE_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt,rel_lub_Positiveness_2446c6015248dfd2->createContext());
CREATE_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt,rel_new_Positiveness_74d7aa09d76e3f24->createContext());
for(const auto& env0 : *rel_new_Positiveness_74d7aa09d76e3f24) {
Tuple<RamDomain,1> env1;
bool shouldRunNested = true;
RamDomain res0 = env0[1];
auto range = rel_new_Positiveness_74d7aa09d76e3f24->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_new_Positiveness_74d7aa09d76e3f24_op_ctxt));
for(const auto& env1 : range) {
if( (ramBitCast<RamDomain>(env1[1]) != ramBitCast<RamDomain>(env0[1]))) {
shouldRunNested = true;
res0 = irTypeLub(&symTable, &recordTable, res0, env1[1]);
}
}
env1[0] = ramBitCast(res0);
if (shouldRunNested) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env1[0])}};
rel_lub_Positiveness_2446c6015248dfd2->insert(tuple,READ_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt));
}
}
}
();rel_new_Positiveness_74d7aa09d76e3f24->purge();
[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt,rel_lub_Positiveness_2446c6015248dfd2->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
for(const auto& env0 : *rel_lub_Positiveness_2446c6015248dfd2) {
auto range = rel_Positiveness_f124c68449d9654b->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt));
for(const auto& env1 : range) {
if( !((ramBitCast<RamDomain>(env1[1]) == ramBitCast<RamDomain>(irTypeLub(&symTable, &recordTable,env0[1],env1[1]))))) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(irTypeLub(&symTable, &recordTable,env0[1],env1[1]))}};
rel_delta_Positiveness_cacdcf6defc09c39->insert(tuple,READ_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt));
}
}
}
}
();[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_lub_Positiveness_2446c6015248dfd2_op_ctxt,rel_lub_Positiveness_2446c6015248dfd2->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
for(const auto& env0 : *rel_lub_Positiveness_2446c6015248dfd2) {
if( !(!rel_Positiveness_f124c68449d9654b->lowerUpperRange_10(Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,2>{{ramBitCast(env0[0]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt)).empty())) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_delta_Positiveness_cacdcf6defc09c39->insert(tuple,READ_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt));
}
}
}
();rel_lub_Positiveness_2446c6015248dfd2->purge();
[&](){
CREATE_OP_CONTEXT(rel_delta_Positiveness_cacdcf6defc09c39_op_ctxt,rel_delta_Positiveness_cacdcf6defc09c39->createContext());
CREATE_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt,rel_Positiveness_f124c68449d9654b->createContext());
for(const auto& env0 : *rel_delta_Positiveness_cacdcf6defc09c39) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_Positiveness_f124c68449d9654b->insert(tuple,READ_OP_CONTEXT(rel_Positiveness_f124c68449d9654b_op_ctxt));
}
}
();loop_counter = (ramBitCast<RamUnsigned>(loop_counter) + ramBitCast<RamUnsigned>(RamUnsigned(1)));
iter++;
}
iter = 0;
rel_delta_Positiveness_cacdcf6defc09c39->purge();
rel_new_Positiveness_74d7aa09d76e3f24->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{R"_(IO)_",R"_(file)_"},{R"_(attributeNames)_",R"_(id	type)_"},{R"_(auxArity)_",R"_(0)_"},{R"_(name)_",R"_(Positiveness)_"},{R"_(operation)_",R"_(output)_"},{R"_(output-dir)_",R"_(.)_"},{R"_(params)_",R"_({"records": {}, "relation": {"arity": 2, "params": ["id", "type"]}})_"},{R"_(types)_",R"_({"ADTs": {"+:irType": {"arity": 7, "branches": [{"name": "Any", "types": []}, {"name": "Bottom", "types": []}, {"name": "Negative", "types": []}, {"name": "NonNegative", "types": []}, {"name": "NonPositive", "types": []}, {"name": "Positive", "types": []}, {"name": "Zero", "types": []}], "enum": true}}, "records": {}, "relation": {"arity": 2, "types": ["i:number", "+:irType"]}})_"}});
if (outputDirectory == "-"){directiveMap["IO"] = "stdout"; directiveMap["headers"] = "true";}
else if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Positiveness_f124c68449d9654b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (pruneImdtRels) rel_edge_04d25f5060e9043b->purge();
if (pruneImdtRels) rel_vertex_bd7050498d9dc077->purge();
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_edge_9543a759b165a2cb {
public:
 Stratum_edge_9543a759b165a2cb(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_000_iiii__0_2_3_1__1011__1111::Type& rel_edge_04d25f5060e9043b);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_000_iiii__0_2_3_1__1011__1111::Type* rel_edge_04d25f5060e9043b;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_edge_9543a759b165a2cb::Stratum_edge_9543a759b165a2cb(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_000_iiii__0_2_3_1__1011__1111::Type& rel_edge_04d25f5060e9043b):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_edge_04d25f5060e9043b(&rel_edge_04d25f5060e9043b){
}

void Stratum_edge_9543a759b165a2cb::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{R"_(IO)_",R"_(file)_"},{R"_(attributeNames)_",R"_(src;dst;category;label)_"},{R"_(auxArity)_",R"_(0)_"},{R"_(delimiter)_",R"_(;)_"},{R"_(fact-dir)_",R"_(.)_"},{R"_(filename)_",R"_(../samples/sample1/edges.csv)_"},{R"_(name)_",R"_(edge)_"},{R"_(operation)_",R"_(input)_"},{R"_(params)_",R"_({"records": {}, "relation": {"arity": 4, "params": ["src", "dst", "category", "label"]}})_"},{R"_(types)_",R"_({"ADTs": {"+:irType": {"arity": 7, "branches": [{"name": "Any", "types": []}, {"name": "Bottom", "types": []}, {"name": "Negative", "types": []}, {"name": "NonNegative", "types": []}, {"name": "NonPositive", "types": []}, {"name": "Positive", "types": []}, {"name": "Zero", "types": []}], "enum": true}}, "records": {}, "relation": {"arity": 4, "types": ["i:number", "i:number", "s:symbol", "s:symbol"]}})_"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_edge_04d25f5060e9043b);
} catch (std::exception& e) {std::cerr << "Error loading edge data: " << e.what() << '\n';
exit(1);
}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_vertex_53aba3f7ebe0276c {
public:
 Stratum_vertex_53aba3f7ebe0276c(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type& rel_vertex_bd7050498d9dc077);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type* rel_vertex_bd7050498d9dc077;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_vertex_53aba3f7ebe0276c::Stratum_vertex_53aba3f7ebe0276c(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type& rel_vertex_bd7050498d9dc077):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_vertex_bd7050498d9dc077(&rel_vertex_bd7050498d9dc077){
}

void Stratum_vertex_53aba3f7ebe0276c::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{R"_(IO)_",R"_(file)_"},{R"_(attributeNames)_",R"_(id;kind;category;label)_"},{R"_(auxArity)_",R"_(0)_"},{R"_(delimiter)_",R"_(;)_"},{R"_(fact-dir)_",R"_(.)_"},{R"_(filename)_",R"_(../samples/sample1/vertices.csv)_"},{R"_(name)_",R"_(vertex)_"},{R"_(operation)_",R"_(input)_"},{R"_(params)_",R"_({"records": {}, "relation": {"arity": 4, "params": ["id", "kind", "category", "label"]}})_"},{R"_(types)_",R"_({"ADTs": {"+:irType": {"arity": 7, "branches": [{"name": "Any", "types": []}, {"name": "Bottom", "types": []}, {"name": "Negative", "types": []}, {"name": "NonNegative", "types": []}, {"name": "NonPositive", "types": []}, {"name": "Positive", "types": []}, {"name": "Zero", "types": []}], "enum": true}}, "records": {}, "relation": {"arity": 4, "types": ["i:number", "s:symbol", "s:symbol", "s:symbol"]}})_"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_vertex_bd7050498d9dc077);
} catch (std::exception& e) {std::cerr << "Error loading vertex data: " << e.what() << '\n';
exit(1);
}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Sf_a: public SouffleProgram {
public:
 Sf_a();
 ~Sf_a();
void run();
void runAll(std::string inputDirectoryArg = "",std::string outputDirectoryArg = "",bool performIOArg = true,bool pruneImdtRelsArg = true);
void printAll([[maybe_unused]] std::string outputDirectoryArg = "");
void loadAll([[maybe_unused]] std::string inputDirectoryArg = "");
void dumpInputs();
void dumpOutputs();
SymbolTable& getSymbolTable();
RecordTable& getRecordTable();
void setNumThreads(std::size_t numThreadsValue);
void executeSubroutine(std::string name,const std::vector<RamDomain>& args,std::vector<RamDomain>& ret);
private:
void runFunction(std::string inputDirectoryArg,std::string outputDirectoryArg,bool performIOArg,bool pruneImdtRelsArg);
SymbolTableImpl symTable;
SpecializedRecordTable<0> recordTable;
ConcurrentCache<std::string,std::regex> regexCache;
std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain, souffle::RamDomain)> binaryOpOnTypes;
std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)> irTypeLub;
std::function<souffle::RamSigned(const char *)> stoi;
std::function<souffle::RamDomain(souffle::SymbolTable*, souffle::RecordTable*, souffle::RamDomain, souffle::RamDomain)> unaryOpOnType;
Own<t_btree_000_iiii__0_2_3_1__1011__1111::Type> rel_edge_04d25f5060e9043b;
souffle::RelationWrapper<t_btree_000_iiii__0_2_3_1__1011__1111::Type> wrapper_rel_edge_04d25f5060e9043b;
Own<t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type> rel_vertex_bd7050498d9dc077;
souffle::RelationWrapper<t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type> wrapper_rel_vertex_bd7050498d9dc077;
Own<t_btree_010_ii__0_1__11__10::Type> rel_Positiveness_f124c68449d9654b;
souffle::RelationWrapper<t_btree_010_ii__0_1__11__10::Type> wrapper_rel_Positiveness_f124c68449d9654b;
Own<t_btree_010_ii__0_1__11::Type> rel_lub_Positiveness_2446c6015248dfd2;
Own<t_btree_000_ii__0_1__11__10::Type> rel_new_Positiveness_74d7aa09d76e3f24;
Own<t_btree_010_ii__0_1__11__10::Type> rel_delta_Positiveness_cacdcf6defc09c39;
Stratum_Positiveness_c6f13be59ac1c916 stratum_Positiveness_b6f963a4df262888;
Stratum_edge_9543a759b165a2cb stratum_edge_31e40d0d94fe9f7c;
Stratum_vertex_53aba3f7ebe0276c stratum_vertex_36b094602fb3095a;
std::string inputDirectory;
std::string outputDirectory;
SignalHandler* signalHandler{SignalHandler::instance()};
std::atomic<RamDomain> ctr{};
std::atomic<std::size_t> iter{};
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Sf_a::Sf_a():
symTable({
  R"_(Literal)_",
  R"_(UnaryOperation)_",
  R"_(Data)_",
  R"_(operand)_",
  R"_(BinaryOperation)_",
  R"_(left)_",
  R"_(right)_",
}),
recordTable(),
regexCache(),
rel_edge_04d25f5060e9043b(mk<t_btree_000_iiii__0_2_3_1__1011__1111::Type>()),
wrapper_rel_edge_04d25f5060e9043b(0, *rel_edge_04d25f5060e9043b, *this, "edge", std::array<const char *,4>{{"i:number","i:number","s:symbol","s:symbol"}}, std::array<const char *,4>{{"src","dst","category","label"}}, 0),
rel_vertex_bd7050498d9dc077(mk<t_btree_000_iiii__0_2__1_0_2_3__1010__1111__0100::Type>()),
wrapper_rel_vertex_bd7050498d9dc077(1, *rel_vertex_bd7050498d9dc077, *this, "vertex", std::array<const char *,4>{{"i:number","s:symbol","s:symbol","s:symbol"}}, std::array<const char *,4>{{"id","kind","category","label"}}, 0),
rel_Positiveness_f124c68449d9654b(mk<t_btree_010_ii__0_1__11__10::Type>()),
wrapper_rel_Positiveness_f124c68449d9654b(2, *rel_Positiveness_f124c68449d9654b, *this, "Positiveness", std::array<const char *,2>{{"i:number","+:irType"}}, std::array<const char *,2>{{"id","type"}}, 1),
rel_lub_Positiveness_2446c6015248dfd2(mk<t_btree_010_ii__0_1__11::Type>()),
rel_new_Positiveness_74d7aa09d76e3f24(mk<t_btree_000_ii__0_1__11__10::Type>()),
rel_delta_Positiveness_cacdcf6defc09c39(mk<t_btree_010_ii__0_1__11__10::Type>()),
stratum_Positiveness_b6f963a4df262888(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_delta_Positiveness_cacdcf6defc09c39,*rel_lub_Positiveness_2446c6015248dfd2,*rel_new_Positiveness_74d7aa09d76e3f24,*rel_Positiveness_f124c68449d9654b,*rel_edge_04d25f5060e9043b,*rel_vertex_bd7050498d9dc077,binaryOpOnTypes,irTypeLub,stoi,unaryOpOnType),
stratum_edge_31e40d0d94fe9f7c(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_edge_04d25f5060e9043b),
stratum_vertex_36b094602fb3095a(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_vertex_bd7050498d9dc077){
addRelation("edge", wrapper_rel_edge_04d25f5060e9043b, true, false);
addRelation("vertex", wrapper_rel_vertex_bd7050498d9dc077, true, false);
addRelation("Positiveness", wrapper_rel_Positiveness_f124c68449d9654b, false, true);
binaryOpOnTypes = functors::binaryOpOnTypes;
irTypeLub = functors::irTypeLub;
stoi = functors::stoi;
unaryOpOnType = functors::unaryOpOnType;
}

 Sf_a::~Sf_a(){
}

void Sf_a::runFunction(std::string inputDirectoryArg,std::string outputDirectoryArg,bool performIOArg,bool pruneImdtRelsArg){

    this->inputDirectory  = std::move(inputDirectoryArg);
    this->outputDirectory = std::move(outputDirectoryArg);
    this->performIO       = performIOArg;
    this->pruneImdtRels   = pruneImdtRelsArg;

    // set default threads (in embedded mode)
    // if this is not set, and omp is used, the default omp setting of number of cores is used.
#if defined(_OPENMP)
    if (0 < getNumThreads()) { omp_set_num_threads(static_cast<int>(getNumThreads())); }
#endif

    signalHandler->set();
// -- query evaluation --
{
 std::vector<RamDomain> args, ret;
stratum_edge_31e40d0d94fe9f7c.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_vertex_36b094602fb3095a.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_Positiveness_b6f963a4df262888.run(args, ret);
}

// -- relation hint statistics --
signalHandler->reset();
}

void Sf_a::run(){
runFunction("", "", false, false);
}

void Sf_a::runAll(std::string inputDirectoryArg,std::string outputDirectoryArg,bool performIOArg,bool pruneImdtRelsArg){
runFunction(inputDirectoryArg, outputDirectoryArg, performIOArg, pruneImdtRelsArg);
}

void Sf_a::printAll([[maybe_unused]] std::string outputDirectoryArg){
try {std::map<std::string, std::string> directiveMap({{R"_(IO)_",R"_(file)_"},{R"_(attributeNames)_",R"_(id	type)_"},{R"_(auxArity)_",R"_(0)_"},{R"_(name)_",R"_(Positiveness)_"},{R"_(operation)_",R"_(output)_"},{R"_(output-dir)_",R"_(.)_"},{R"_(params)_",R"_({"records": {}, "relation": {"arity": 2, "params": ["id", "type"]}})_"},{R"_(types)_",R"_({"ADTs": {"+:irType": {"arity": 7, "branches": [{"name": "Any", "types": []}, {"name": "Bottom", "types": []}, {"name": "Negative", "types": []}, {"name": "NonNegative", "types": []}, {"name": "NonPositive", "types": []}, {"name": "Positive", "types": []}, {"name": "Zero", "types": []}], "enum": true}}, "records": {}, "relation": {"arity": 2, "types": ["i:number", "+:irType"]}})_"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Positiveness_f124c68449d9654b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}

void Sf_a::loadAll([[maybe_unused]] std::string inputDirectoryArg){
try {std::map<std::string, std::string> directiveMap({{R"_(IO)_",R"_(file)_"},{R"_(attributeNames)_",R"_(id;kind;category;label)_"},{R"_(auxArity)_",R"_(0)_"},{R"_(delimiter)_",R"_(;)_"},{R"_(fact-dir)_",R"_(.)_"},{R"_(filename)_",R"_(../samples/sample1/vertices.csv)_"},{R"_(name)_",R"_(vertex)_"},{R"_(operation)_",R"_(input)_"},{R"_(params)_",R"_({"records": {}, "relation": {"arity": 4, "params": ["id", "kind", "category", "label"]}})_"},{R"_(types)_",R"_({"ADTs": {"+:irType": {"arity": 7, "branches": [{"name": "Any", "types": []}, {"name": "Bottom", "types": []}, {"name": "Negative", "types": []}, {"name": "NonNegative", "types": []}, {"name": "NonPositive", "types": []}, {"name": "Positive", "types": []}, {"name": "Zero", "types": []}], "enum": true}}, "records": {}, "relation": {"arity": 4, "types": ["i:number", "s:symbol", "s:symbol", "s:symbol"]}})_"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_vertex_bd7050498d9dc077);
} catch (std::exception& e) {std::cerr << "Error loading vertex data: " << e.what() << '\n';
exit(1);
}
try {std::map<std::string, std::string> directiveMap({{R"_(IO)_",R"_(file)_"},{R"_(attributeNames)_",R"_(src;dst;category;label)_"},{R"_(auxArity)_",R"_(0)_"},{R"_(delimiter)_",R"_(;)_"},{R"_(fact-dir)_",R"_(.)_"},{R"_(filename)_",R"_(../samples/sample1/edges.csv)_"},{R"_(name)_",R"_(edge)_"},{R"_(operation)_",R"_(input)_"},{R"_(params)_",R"_({"records": {}, "relation": {"arity": 4, "params": ["src", "dst", "category", "label"]}})_"},{R"_(types)_",R"_({"ADTs": {"+:irType": {"arity": 7, "branches": [{"name": "Any", "types": []}, {"name": "Bottom", "types": []}, {"name": "Negative", "types": []}, {"name": "NonNegative", "types": []}, {"name": "NonPositive", "types": []}, {"name": "Positive", "types": []}, {"name": "Zero", "types": []}], "enum": true}}, "records": {}, "relation": {"arity": 4, "types": ["i:number", "i:number", "s:symbol", "s:symbol"]}})_"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_edge_04d25f5060e9043b);
} catch (std::exception& e) {std::cerr << "Error loading edge data: " << e.what() << '\n';
exit(1);
}
}

void Sf_a::dumpInputs(){
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "vertex";
rwOperation["types"] = R"_({"relation": {"arity": 4, "auxArity": 0, "types": ["i:number", "s:symbol", "s:symbol", "s:symbol"]}})_";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_vertex_bd7050498d9dc077);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "edge";
rwOperation["types"] = R"_({"relation": {"arity": 4, "auxArity": 0, "types": ["i:number", "i:number", "s:symbol", "s:symbol"]}})_";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_edge_04d25f5060e9043b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}

void Sf_a::dumpOutputs(){
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Positiveness";
rwOperation["types"] = R"_({"relation": {"arity": 2, "auxArity": 0, "types": ["i:number", "+:irType"]}})_";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Positiveness_f124c68449d9654b);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}

SymbolTable& Sf_a::getSymbolTable(){
return symTable;
}

RecordTable& Sf_a::getRecordTable(){
return recordTable;
}

void Sf_a::setNumThreads(std::size_t numThreadsValue){
SouffleProgram::setNumThreads(numThreadsValue);
symTable.setNumLanes(getNumThreads());
recordTable.setNumLanes(getNumThreads());
regexCache.setNumLanes(getNumThreads());
}

void Sf_a::executeSubroutine(std::string name,const std::vector<RamDomain>& args,std::vector<RamDomain>& ret){
if (name == "Positiveness") {
stratum_Positiveness_b6f963a4df262888.run(args, ret);
return;}
if (name == "edge") {
stratum_edge_31e40d0d94fe9f7c.run(args, ret);
return;}
if (name == "vertex") {
stratum_vertex_36b094602fb3095a.run(args, ret);
return;}
fatal(("unknown subroutine " + name).c_str());
}

} // namespace  souffle
namespace souffle {
SouffleProgram *newInstance_a(){return new  souffle::Sf_a;}
SymbolTable *getST_a(SouffleProgram *p){return &reinterpret_cast<souffle::Sf_a*>(p)->getSymbolTable();}
} // namespace souffle

#ifndef __EMBEDDED_SOUFFLE__
#include "souffle/CompiledOptions.h"
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"_(positiveness.dl)_",
R"_()_",
R"_()_",
false,
R"_()_",
1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_a obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}
#endif

namespace  souffle {
using namespace souffle;
class factory_Sf_a: souffle::ProgramFactory {
public:
souffle::SouffleProgram* newInstance();
 factory_Sf_a();
private:
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
souffle::SouffleProgram* factory_Sf_a::newInstance(){
return new  souffle::Sf_a();
}

 factory_Sf_a::factory_Sf_a():
souffle::ProgramFactory("a"){
}

} // namespace  souffle
namespace souffle {

#ifdef __EMBEDDED_SOUFFLE__
extern "C" {
souffle::factory_Sf_a __factory_Sf_a_instance;
}
#endif
} // namespace souffle

