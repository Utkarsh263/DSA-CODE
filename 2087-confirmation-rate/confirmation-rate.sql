# Write your MySQL query statement below
Select s.user_id, 
    Round(
        IFNULL(
            AVG(c.action = 'confirmed'),0
        ), 2
    ) as confirmation_rate
From signups s
Left Join confirmations c
on s.user_id = c.user_id
group by s.user_id;