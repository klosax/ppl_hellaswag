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

(26 models in correlation)

Correlation at 200 lines: `y = 77.55 x + 23.46`
</br>R2 = 0.8636

Correlation at 400 lines: `y = 82.79 x + 27.06`
</br>R2 = 0.9049

where `x = (ppl_wrong – ppl_correct) / ppl_correct`

![ppl_hellaswag_400](https://github.com/klosax/ppl_hellaswag/assets/131523366/06a6cfdc-f1b9-40c9-ba7c-df4950903525)
