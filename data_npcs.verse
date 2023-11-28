labyrinth_npc_data_file<public> := module
{
    GetData<public>() : [string]labyrinth_npc_data =
    {
        DataMap : [string]labyrinth_npc_data = map{
            "lyra" => labyrinth_npc_data{ID := "lyra", Name := "Lyra McBride"},
            "steve" => labyrinth_npc_data{ID := "steve", Name := "Steveious"}
        }

        return DataMap
    }
}
