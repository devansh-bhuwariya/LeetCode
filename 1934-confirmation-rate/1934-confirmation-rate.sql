# Write your MySQL query statement below
# s.user_id,count(c.action)
SELECT s.user_id,ROUND(avg(if(c.action='confirmed',1,0)),2) AS confirmation_rate FROM Signups AS s
LEFT JOIN Confirmations AS c on s.user_id=c.user_id
GROUP BY s.user_id;
