SELECT animal_outs.animal_id, animal_outs.name
FROM animal_outs LEFT JOIN animal_ins
/*left join을 outs를 중심으로 시켜서 보호소에 들어온 기록이 없어진 정보를 null처리를 함*/
ON animal_ins.animal_id = animal_outs.animal_id
/*join을 시킬 때, 기록이 있는 정보는 id가 같은 것들끼리(정보가 같은 것들을) join을 함*/
WHERE (animal_ins.animal_id is null)
/*그럼 그 중에서 기록이 사라진 것들은 들어온 정보 중 id가 null이 되어있을 것이니, 그것을 찾음*/
ORDER BY animal_id ASC;