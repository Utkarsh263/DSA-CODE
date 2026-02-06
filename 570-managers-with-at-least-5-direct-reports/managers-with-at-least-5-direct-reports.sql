# Write your MySQL query statement below
SELECT e.name from 
Employee e 
join (
    Select managerId from Employee 
    group by managerId 
    having count(*) >=5
)m 
on e.id = m.managerId;