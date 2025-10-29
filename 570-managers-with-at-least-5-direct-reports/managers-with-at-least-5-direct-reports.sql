# Write your MySQL query statement below
Select e.name from employee e 
join employee r 
on e.id = r.managerId
group by e.id , e.name
having count(r.id) >= 5