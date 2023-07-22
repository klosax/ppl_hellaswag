Extracted from [hellaswag_val.jsonl](https://github.com/rowanz/hellaswag/blob/master/data/hellaswag_val.jsonl):

- `hellaswag_val_correct.txt.200` - The first 200 contexts and the correct endings, one sentence per line.
- `hellaswag_val_wrong.txt.200` - The first 200 contexts and the first wrong endings, one sentence per line.
- `hellaswag_val_correct.txt.400` - The first 400 contexts and the correct endings, one sentence per line.
- `hellaswag_val_wrong.txt.400` - The first 400 contexts and the first wrong endings, one sentence per line.
</br>

- `ppl_correct` = Cumulative perplexity on each line of hellaswag_val_correct.txt
- `ppl_wrong` = Cumulative perplexity on each line of hellaswag_val_wrong.txt
</br>

The following formula linearly correlates with HellaSwag scores at the [Open LLM Leaderboard](https://huggingface.co/spaces/HuggingFaceH4/open_llm_leaderboard).

`(ppl_wrong – ppl_correct) / ppl_correct`
