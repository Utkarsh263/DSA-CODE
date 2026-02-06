# Write your MySQL query statement below
Select e.name 
from employee e
join
    (Select managerId from Employee
    group by managerId
    having count(*) >=5
    )m 
    on e.id = m.managerId;
