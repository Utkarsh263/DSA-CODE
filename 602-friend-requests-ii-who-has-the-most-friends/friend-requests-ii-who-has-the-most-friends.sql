# Write your MySQL query statement below
Select id , count(*) as num
from(
    Select requester_id as id from requestaccepted
    union all
    Select accepter_id as id from requestaccepted
)as all_friends
group by id
order by num desc
limit 1;