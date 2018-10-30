select
	name,
	sum(extendedprice * (1 - discount)) as revenue
from
	customer,
	orders,
	lineitem,
	supplier,
	nation,
	region
where
	customer.custkey = orders.custkey
	and orders.orderkey = lineitem.orderkey
	and supplier.suppkey = lineitem.suppkey
	and nation.nationkey = customer.nationkey
	and nation.nationkey = supplier.nationkey
	and region.regionkey = nation.regionkey
	and ((orderdate date ':2'
	and orderdate < date ':2' + interval '1' year)
	or (name = ':1'))
group by
	name
order by
	revenue desc;

/*
	mainGraph.add_table("nation","name","dimension");
	mainGraph.add_table("orders","orderdate","measure");
	mainGraph.add_table("lineitem","extendedprice","measure");
	mainGraph.add_table("lineitem","discount","measure");*/
