Extracted from [hellaswag_val.jsonl](https://github.com/rowanz/hellaswag/blob/master/data/hellaswag_val.jsonl):

- `hellaswag_val_correct.txt.X` - The first X contexts and the correct endings, one sentence per line.
- `hellaswag_val_wrong.txt.X` - The first X contexts and the first wrong endings, one sentence per line.
</br>

- `ppl_correct` = Cumulative line perplexity of hellaswag_val_correct.txt.X
- `ppl_wrong` = Cumulative line perplexity of hellaswag_val_wrong.txt.X
</br>

The following formula linearly correlates with HellaSwag scores at the [Open LLM Leaderboard](https://huggingface.co/spaces/HuggingFaceH4/open_llm_leaderboard).

`(ppl_wrong – ppl_correct) / ppl_correct`

![ppl_hellaswag_400](https://github.com/klosax/ppl_hellaswag/assets/131523366/06a6cfdc-f1b9-40c9-ba7c-df4950903525)
