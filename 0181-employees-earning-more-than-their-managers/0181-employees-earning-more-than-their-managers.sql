# Write your MySQL query statement belo
select  m.name as employee  from employee as e 
inner join employee as m on e.id = m.managerId
where e.salary < m.salary 