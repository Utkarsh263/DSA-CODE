# Write your MySQL query statement below
-- Select c.name from customers c 
-- left join orders o on c.id = o.customerId
-- where o.id is NULL
-- order by c.name;

Select name as Customers from customers
where id not in(Select customerId from orders)
order by name;