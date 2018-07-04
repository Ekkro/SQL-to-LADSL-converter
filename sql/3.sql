select
	l.orderkey,
	sum(l.extendedprice * (1 - l.discount)) as revenue,
	o.orderdate,
	o.shippriority
from
	customer,
	orders,
	lineitem
where
	c.mktsegment = ':1'
	and c.custkey = o.custkey
	and l.orderkey = o.orderkey
	and o.orderdate < date ':2'
	and l.shipdate > date ':2'
group by
	l.orderkey,
	o.orderdate,
	o.shippriority
order by
	revenue desc,
	o.orderdate;
